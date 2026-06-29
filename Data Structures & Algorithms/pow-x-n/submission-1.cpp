class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        int m = abs(n);
        while(m!=0){
            if(m%2!=0){
                result = result*x;
                m--;
            } else {
                x = x*x;
                m = m/2;
            }

        }
        if(n<0){
            return (1/result);
        }
        return result;
    }
};
