class Twitter {
public:
    unordered_map<int, set<int>> relation;
    unordered_map<int, vector<pair<int,int>>> tweets;
    int time = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId){
        time += 1;
        tweets[userId].insert(tweets[userId].begin(), {time,tweetId});
        if (tweets[userId].size() > 10) tweets[userId].erase(tweets[userId].end());
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> feed = tweets[userId];
        vector<int> res;
        
        for (int i : relation[userId]){
            vector<pair<int,int>> temp = tweets[i];
            feed.insert(feed.end(), temp.begin(), temp.end());
            sort(feed.rbegin(), feed.rend());

            if (feed.size() > 10) feed.erase(feed.begin() + 10, feed.end());
        }

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
        if (relation[followerId].count(followeeId)){
            relation[followerId].erase(followeeId);
        }
    }
};
