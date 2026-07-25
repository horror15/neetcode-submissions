class Solution {
public:
    bool test(vector<int>& matchsticks, int target, vector<int>& sides, int index){
        if(index == matchsticks.size()) return true;
        for(int i=0; i<4; i++){
            if(sides[i]+matchsticks[index] <= target){
                sides[i] += matchsticks[index];
                if(test(matchsticks,target,sides,index+1)) return true;
                sides[i] -= matchsticks[index];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        vector<int>sides(4, 0);
        int sum = 0;
        for(int i=0; i<matchsticks.size(); i++){
            sum += matchsticks[i];

        }
        if(sum%4!=0) return false;
        int target = sum/4;
        sort(matchsticks.rbegin(), matchsticks.rend());
        return test(matchsticks,target,sides,0);
    }
};