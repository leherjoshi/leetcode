class Twitter {
public:

    int timestamp=0;
    unordered_map<int ,vector<pair<int,int>>>tweets;
    unordered_map<int,unordered_set<int>>following;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
    priority_queue<tuple<int,int,int,int>> pq;

    // Add user's latest tweet
    if (!tweets[userId].empty()) {
        int i = tweets[userId].size() - 1;
        pq.push({tweets[userId][i].first,
                 tweets[userId][i].second,
                 userId,
                 i});
    }

    // Add latest tweet of every followed user
    for (int id : following[userId]) {
        if (!tweets[id].empty()) {
            int i = tweets[id].size() - 1;

            pq.push({tweets[id][i].first,
                     tweets[id][i].second,
                     id,
                     i});
        }
    }

    vector<int> ans;

    while (!pq.empty() && ans.size() < 10) {
        auto top = pq.top();
        pq.pop();

        int time = get<0>(top);
        int tweetId = get<1>(top);
        int user = get<2>(top);
        int index = get<3>(top);

        ans.push_back(tweetId);

        // Get this user's previous tweet
        if (index > 0) {
            index--;

            pq.push({
                tweets[user][index].first,
                tweets[user][index].second,
                user,
                index
            });
        }
    }

    return ans;
}
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            following[followerId].insert(followeeId);
        }

    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */