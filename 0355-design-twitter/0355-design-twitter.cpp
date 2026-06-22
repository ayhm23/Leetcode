class Twitter {
private:
    int timer;
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pair<int,int>>> tweets;

public:
    Twitter() {
        timer = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        follows[userId].insert(userId);

        priority_queue<vector<int>> pq;
        // {timestamp, tweetId, userId, index}

        for (int followee : follows[userId]) {
            int sz = tweets[followee].size();

            if (sz > 0) {
                auto &[time, tweetId] = tweets[followee][sz - 1];
                pq.push({time, tweetId, followee, sz - 1});
            }
        }

        vector<int> ans;

        while (!pq.empty() && ans.size() < 10) {

            auto curr = pq.top();
            pq.pop();

            int time = curr[0];
            int tweetId = curr[1];
            int user = curr[2];
            int idx = curr[3];

            ans.push_back(tweetId);

            if (idx > 0) {
                auto &[prevTime, prevTweet] = tweets[user][idx - 1];
                pq.push({prevTime, prevTweet, user, idx - 1});
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
            follows[followerId].erase(followeeId);
    }
};