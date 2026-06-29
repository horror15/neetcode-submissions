class Solution {
public:
    int getSum(int a, int b) {
        unsigned int ua = a;
        unsigned int ub = b;
        int res = 0;
        int carry=0;
        for(int i=0; i<32; i++){
            int t = (ua&1) ^ (ub&1) ^ carry;
            if((ua&1) && (ub&1)) {
                carry=1;
            } else if (carry && ((ua&1) || ((ub&1)))){
                carry=1;
            } else{
                carry=0;
            }
            res |= (t<<i);
            ua = ua>>1;
            ub = ub>>1;
        }
        return res;
    }

};
