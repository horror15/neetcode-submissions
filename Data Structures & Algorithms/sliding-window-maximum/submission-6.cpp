class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>vec;
        priority_queue<pair<int, int>>pq;
        int left=0, right=k-1;
        for(int i=0; i<k-1; i++){
            pq.push({nums[i], i});
        }
        while(right<nums.size()){
            pq.push({nums[right], right});
            while(pq.top().second < left){
                pq.pop();
            }
            vec.push_back(pq.top().first);
            left++;
            right++;
        }
        return vec;
    }
};
