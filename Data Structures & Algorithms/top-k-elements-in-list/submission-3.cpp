class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> vec;
        unordered_map<int, int>mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]] += 1;
        }
        for(auto [key, value]: mp){
            pq.push({value, key});
            if(pq.size() > k){
                pq.pop();
            }
        }

        while(pq.size()!=0){
            pair<int, int> p = pq.top(); 
            vec.push_back(p.second);
            pq.pop();

        }
        return vec;

    }
};
