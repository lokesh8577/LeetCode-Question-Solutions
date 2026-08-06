class Twitter {
public:
    int timer = 0;

    unordered_map<int, vector<pair<int, int>>> post;
    unordered_map<int, unordered_set<int>> followList;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        post[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;

        followList[userId].insert(userId);

        for (auto user : followList[userId]) {
            for (auto p : post[user]) {
                pq.push(p);
            }
        }

        vector<int> feed;

        while (!pq.empty() && feed.size() < 10) {
            feed.push_back(pq.top().second);
            pq.pop();
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }

        followList[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }

        followList[followerId].erase(followeeId);
    }
};