class Twitter {
public:
    int timer;
    unordered_map<int,vector<pair<int,int>>> tweets;
    unordered_map<int,unordered_set<int>> following;
    Twitter() {
        timer=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        for(auto user:tweets[userId]){
            pq.push(user);
        }
        for(auto user:following[userId]){
            for(auto tweet:tweets[user]){
                pq.push(tweet);
            }
        }
        vector<int> ans;
        while(!pq.empty() && ans.size()<10){
            auto top=pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId) return;
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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