class Solution {
public:
    bool backtrack(vector<int> &matchsticks, vector<int> &visited, int sub_sum, int start, int current, int k) {
        if(k==1) return true;
        if(sub_sum == current){
            return backtrack(matchsticks, visited, sub_sum, 0, 0, k-1);
        }
        for(int i=start; i<matchsticks.size(); i++){
            if(visited[i] || current+matchsticks[i] > sub_sum){
                continue;
            }
            visited[i] = true;
            if(backtrack(matchsticks, visited, sub_sum, i+1, current+matchsticks[i], k)) {
                return true;
            }
            visited[i] = false;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        vector<int> visited(matchsticks.size(), false);
        for (int i=0; i<matchsticks.size(); i++){
            sum += matchsticks[i];
        }
        if(sum%4 !=0){
            return false;
        }
        int sub_sum = sum/4;
        int current = 0;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return backtrack(matchsticks, visited, sub_sum, 0, current, 4);
    }
};