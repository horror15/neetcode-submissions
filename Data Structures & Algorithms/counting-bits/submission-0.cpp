class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>vec(n+1, 0);
        int i=2;
        vec[0] = 0;
        vec[1] = 1; 
        while(i<=n){
            if(i%2==0){
                vec[i] = vec[i/2];
            } else {
                vec[i] = vec[i/2] + 1;
            }
            i++;
        }
        return vec;
    }
};
