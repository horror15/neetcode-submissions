class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<vector<int>>pick;
        vector<vector<int>>drop;
        for(int i=0; i<trips.size();i++){
            pick.push_back({trips[i][1], trips[i][0]});
        }
        for(int i=0; i<trips.size();i++){
            drop.push_back({trips[i][2], trips[i][0]});
        }
        sort(pick.begin(), pick.end());
        sort(drop.begin(), drop.end());
        int total_pass = 0;
        int i = 0;
        int j = 0;
        while(i < pick.size()){
            total_pass += pick[i][1]; 
            while(j < drop.size()){
                if(pick[i][0] >= drop[j][0]){
                    total_pass -= drop[j][1];
                    j++;
                } else {
                    break;
                }
            }
            if(total_pass > capacity){
                return false;
            }
            i++;
        }
        return true;
    }
};