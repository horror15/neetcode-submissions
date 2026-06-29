class Twitter {
public:
    unordered_map<int, unordered_set<int>>mp;
    int time = 0;
    unordered_map<int, vector<pair<int, int>>>tweet;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>>pq;
        vector<int>vec;
        mp[userId].insert(userId);
        for(auto user: mp[userId]){
            if(tweet[user].size() > 0){
                pq.push({tweet[user].back().first, tweet[user].back().second, user, tweet[user].size()-1});
            }
        }

        while(!pq.empty() && vec.size() < 10){
            vec.push_back(pq.top()[1]);
            vector<int>val = pq.top();
            int index = val[3]- 1;
            int userId = val[2];
            pq.pop();
            if (index > -1){
                int timestamp = tweet[val[2]][index].first;
                int tweetId = tweet[val[2]][index].second;
                pq.push({timestamp ,tweetId,userId,index});
            }
        }
        return vec;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mp[followerId].erase(followeeId);
    }
};
