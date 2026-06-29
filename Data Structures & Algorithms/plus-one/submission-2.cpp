class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int s = digits.size()-1;
        long result = 0;
        vector<int> vec;
        for(int i=0; i<digits.size(); i++){
            result+=digits[i]*pow(10, s);
            s--;
        }
        result++;
        cout<<result;
        long rem = result%10;
        result = result/10;
        while(result!=0){
            vec.push_back(rem);
            rem = result%10;
            result = result/10;
        }
        vec.push_back(rem);
        reverse(vec.begin(), vec.end());
        return vec;
    }
};
