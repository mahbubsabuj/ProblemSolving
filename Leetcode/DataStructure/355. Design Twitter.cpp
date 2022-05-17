class Twitter {
public:
    map<int, set<int>> followIds;
    map<int, vector<int>> tweetsId;
    map<int, int> postTime;
    int timeNow = 1;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweetsId[userId].push_back(tweetId);
        postTime[tweetId] = timeNow++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> postIds;
        for (int follower : followIds[userId]) {
            for (int postId : tweetsId[follower]) {
                postIds.push_back(postId);
            }
        }
        for (int postId : tweetsId[userId]) {
            postIds.push_back(postId);
        }
        sort (postIds.begin(), postIds.end(), [&] (int x, int y) {
            return postTime[x] < postTime[y];
        });
        vector<int> res;
        for (int i = (int) postIds.size() - 1; i >= max(0, (int) postIds.size() - 10); --i) {
            res.push_back(postIds[i]);
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followIds[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followIds[followerId].erase(followeeId);
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