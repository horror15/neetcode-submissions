class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>s;
        if(n==1){
            return true;
        }
        s.insert(n);
        int new_num = n;
        int div = 0;
        int rem = 0;
        while(true){
            int num = new_num;
            new_num = 0;
            rem = num%10;
            div = num/10;
            while(div!=0){
                new_num+=(rem*rem);
                rem = div%10;
                div = div/10;
            }
            new_num+=(rem*rem);
            if(new_num==1){
                return true;
            }
            if(s.find(new_num) == s.end()){
                s.insert(new_num);
            } else {
                break;
            }
        }
        return false;
    }
};
