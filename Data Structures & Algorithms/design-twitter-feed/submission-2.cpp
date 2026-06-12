class Twitter {
private:
    unordered_map<int,vector<pair<int,int>>>tweets;
    unordered_map<int,unordered_set<int>>followees; 
    int cntr = 0;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({cntr,tweetId});
        cntr++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>res;
        for(int x:followees[userId]){
            for(auto a: tweets[x]){
                res.push(a);
            }
        }
        for(auto a: tweets[userId]){
            res.push(a);
        }
        vector<int>ans;
        int r=0;
        while(!res.empty() && r<10){
            auto x=res.top();
            ans.push_back(x.second);
            res.pop();
            r++;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId) return;
        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        auto it = find(followees[followerId].begin(), followees[followerId].end(), followeeId);
        if (it != followees[followerId].end()) {
            followees[followerId].erase(it);
        }
    }
};
