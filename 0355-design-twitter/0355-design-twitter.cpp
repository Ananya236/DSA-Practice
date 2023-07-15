class Twitter {
public:
    vector<pair<int,int>> feeds;
    vector<unordered_set<int>> followings;
    int maxFeedCount=10;
    
    Twitter() {
        followings.resize(501);
    }
    
    void postTweet(int userId, int tweetId) {
        feeds.push_back({tweetId, userId});
    }
    
    vector<int> getNewsFeed(int userId) {
        int n = feeds.size(), cnt = maxFeedCount;
        vector<int> userFeeds;
        for(int i=n-1; i>=0 && cnt; i--){
            if(feeds[i].second == userId || 
               followings[userId].find(feeds[i].second) != followings[userId].end())
            {
                userFeeds.push_back(feeds[i].first);
                cnt--;
            }
        }
        return userFeeds;
    }
    
    void follow(int followerId, int followeeId) {
        followings[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followings[followerId].erase(followeeId);
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