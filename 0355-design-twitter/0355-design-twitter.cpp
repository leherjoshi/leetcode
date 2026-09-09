class Twitter {
    int timestamp = 0;
    // userId -> list of (time, tweetId) in the order posted (so back = most recent)
    unordered_map<int, vector<pair<int,int>>> tweets;
    // followerId -> set of followeeId
    unordered_map<int, unordered_set<int>> following;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        // max-heap of (time, tweetId, userId, indexIntoTheirVector)
        priority_queue<tuple<int,int,int,int>> heap;

        // seed with the user's own last tweet
        auto seed = [&](int uid) {
            auto& v = tweets[uid];
            if (!v.empty()) {
                int idx = v.size() - 1;
                heap.push({v[idx].first, v[idx].second, uid, idx});
            }
        };

        seed(userId);
        for (int followeeId : following[userId]) seed(followeeId);

        vector<int> result;
        while (!heap.empty() && result.size() < 10) {
            auto [time, tid, uid, idx] = heap.top();
            heap.pop();
            result.push_back(tid);

            if (idx > 0) {
                idx--;
                heap.push({tweets[uid][idx].first, tweets[uid][idx].second, uid, idx});
            }
        }
        return result;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};