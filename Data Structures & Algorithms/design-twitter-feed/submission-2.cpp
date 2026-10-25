class Twitter {
public:
    unordered_map<int, unordered_set<int>>mp;
    unordered_map<int, vector<pair<int, int>>>mm;
    int timestamp = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        mm[userId].push_back({timestamp, tweetId});
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>out;
        priority_queue<pair<int, int>>pq;
        //followee tweet
        for(auto& followee: mp[userId]){
            for(auto& tt: mm[followee]){
                pair<int, int>p = tt;
                pq.push(p);
            }
        }
        // user own tweet
        for(auto& tt: mm[userId]){
                pair<int, int>p = tt;
                pq.push(p);
        }
        int count = 10;
        while(!pq.empty() && count!=0){
            out.push_back(pq.top().second);
            pq.pop();
            count--;
        }
        return out;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mp[followerId].erase(followeeId);
    }
};
