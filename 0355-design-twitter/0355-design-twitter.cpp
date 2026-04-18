class Twitter {
public:
    int time;
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> follows;

    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        // max heap: {time, tweetId, userId, index}
        using T = tuple<int,int,int,int>;
        priority_queue<T> pq;

        // include self
        follows[userId].insert(userId);

        // push latest tweet of each followee
        for (int user : follows[userId]) {
            if (tweets[user].empty()) continue;

            int idx = tweets[user].size() - 1;
            auto [t, id] = tweets[user][idx];
            pq.push({t, id, user, idx});
        }

        // get top 10 tweets
        while (!pq.empty() && res.size() < 10) {
            auto [t, id, user, idx] = pq.top();
            pq.pop();

            res.push_back(id);

            // push next tweet from same user
            if (idx > 0) {
                auto [nt, nid] = tweets[user][idx - 1];
                pq.push({nt, nid, user, idx - 1});
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
            follows[followerId].erase(followeeId);
    }
};