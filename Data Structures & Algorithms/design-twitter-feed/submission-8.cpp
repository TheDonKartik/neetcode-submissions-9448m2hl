class Twitter {
public:
    unordered_map<int, set<int>> relation;
    unordered_map<int, vector<pair<int,int>>> tweets;
    int time = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId){
        time += 1;
        tweets[userId].push_back({time,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> feed = tweets[userId];
        vector<int> res;
        
        for (int i : relation[userId]){
            feed.insert(feed.end(), tweets[i].begin(), tweets[i].end());
        }
        sort(feed.rbegin(), feed.rend());
        if (feed.size() > 10) feed.erase(feed.begin() + 10, feed.end());
        for (pair<int,int> i : feed){
            res.push_back(i.second);
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
        relation[followerId].insert(followeeId); 
    }
    
    void unfollow(int followerId, int followeeId) {
        relation[followerId].erase(followeeId);
        
    }
};
