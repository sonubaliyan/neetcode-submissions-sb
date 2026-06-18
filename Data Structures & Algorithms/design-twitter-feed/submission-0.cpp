class Twitter {
private:
    int timestamp;
    unordered_map<int, vector<pair<int, int>>> userTweets;
    unordered_map<int, unordered_set<int>> following;

public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        
        // Add current user's tweets
        for (auto& tweet : userTweets[userId]) {
            pq.push(tweet);
        }
        
        // Add followees' tweets
        for (int followeeId : following[userId]) {
            for (auto& tweet : userTweets[followeeId]) {
                pq.push(tweet);
            }
        }
        
        vector<int> result;
        for (int i = 0; i < 10 && !pq.empty(); ++i) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};