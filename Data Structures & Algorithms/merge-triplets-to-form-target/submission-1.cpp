class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool finalfirst  = false;
        bool finalsecond = false;
        bool finalthird = false;
        for(int i=0; i<triplets.size(); i++){
            int first = false;
            int second = false;
            int third = false;
            for(int j=0; j<3; j++){
                if(triplets[i][j] == target[j]){
                    if(j==0) {
                        first = true;
                    } else if(j==1){
                        second = true;
                    } else{
                        third = true;
                    }
                } 
                if(triplets[i][j] > target[j]){
                    first = false;
                    second = false;
                    third = false;
                    break;
                }             
            }
            if(!finalfirst) finalfirst = first;
            if(!finalsecond) finalsecond = second;
            if(!finalthird) finalthird = third;

        }
        if(finalfirst && finalsecond && finalthird) return true;
        return false;
    }
};
