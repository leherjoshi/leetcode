class Twitter {
    int timestamp = 0;
    // userId -> list of (time, tweetId), in order posted
    unordered_map<int, vector<pair<int,int>>> tweets;
    // followerId -> set of followeeId
    unordered_map<int, unordered_set<int>> following;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> candidates; // (time, tweetId)

        // add my own last 10 tweets
        auto& mine = tweets[userId];
        for (int i = mine.size() - 1; i >= 0 && i >= (int)mine.size() - 10; i--)
            candidates.push_back(mine[i]);

        // add last 10 tweets of everyone I follow
        for (int followeeId : following[userId]) {
            auto& theirs = tweets[followeeId];
            for (int i = theirs.size() - 1; i >= 0 && i >= (int)theirs.size() - 10; i--)
                candidates.push_back(theirs[i]);
        }

        // sort by time, most recent first
        sort(candidates.begin(), candidates.end(), greater<>());

        vector<int> result;
        for (int i = 0; i < (int)candidates.size() && i < 10; i++)
            result.push_back(candidates[i].second);

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