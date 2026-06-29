class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        vector<int> vec;
        int carry=0;
        int val = digits[i] + 1;
        if(val>9){
            carry = 1;
            vec.push_back(0);
        } else {
            vec.push_back(val);
        }
        i--;
        while(i>=0){
            val = digits[i] + carry;
            if(val>9){
                carry = 1;
                vec.push_back(0);
            } else{
                carry = 0;
                vec.push_back(val);
            }
            i--;
        }
        if(carry==1){
            vec.push_back(1);
        }
        reverse(vec.begin(), vec.end());
        return vec;
    }
};
