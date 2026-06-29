class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int elem = INT_MIN;
        for(int i=0; i<piles.size(); i++){
            elem = max(elem, piles[i]);
        }
        int res = INT_MAX;
        int left=1, right=elem;
        while(left<=right){
            int mid = (left+right)/2;
            int hours = 0;
            for(int i=0; i<piles.size(); i++){
                hours += piles[i]/mid;
                if((piles[i]%mid)!=0){
                    hours += 1;
                }
            }
            if(hours <= h){
                res = min(res, mid);
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return res;
    }
};
