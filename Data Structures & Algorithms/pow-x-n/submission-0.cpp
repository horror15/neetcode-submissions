class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        if(n>=0){
            while(n!=0){
                result = result*x;
                n--;
            }
         } else {
            while(n!=0){
                result = result*(1/x);
                n++;
            }
         }
         return result;

    }
};
