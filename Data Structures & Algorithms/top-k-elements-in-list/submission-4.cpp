class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        unordered_map<int, int>mp;

        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for(const auto& pair:mp){
            if(pq.size()<k){
                pq.push({pair.second, pair.first});
            } else {
                if(pq.top().first<pair.second){
                    pq.pop();
                    pq.push({pair.second, pair.first});
                }
            }
        }
        vector<int>out;
        while(!pq.empty()){
            out.push_back(pq.top().second);
            pq.pop();
        }
        return out;
    }
};
