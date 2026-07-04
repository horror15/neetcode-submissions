class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        int max_num = INT_MIN;
        int min_cap = INT_MAX;
        for(int i=0; i<weights.size(); i++){
            sum += weights[i];
            max_num = max(max_num, weights[i]);
        }
        int left=max_num, right=sum;
        while(left<=right){
            int mid = (left+right)/2;
            int cap = 0;
            int day = 0;
            for(int i=0; i<weights.size(); i++){
                cap += weights[i];
                if(cap > mid){
                    cap = weights[i];
                    day += 1;
                }
            }
            day += 1;
            if(day <= days){
                right = mid-1;
                min_cap = min(min_cap, mid);
            } else {
                left = mid+1;
            }
        }
        return min_cap;
    }
};