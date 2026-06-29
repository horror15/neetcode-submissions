class Solution {
public:
    string multiply(string num1, string num2) {
        string temp;
        vector<int>digit(num1.size()+num2.size(), 0);
        if(num1.size() > num2.size()){
            temp = num1;
            num1 = num2;
            num2 = temp;
        }
        for(int i=num1.size()-1; i>-1; i--){
            for(int j=num2.size()-1; j>-1; j--){
                int mul = (num1[i] - '0')*(num2[j] - '0');
                int sum = digit[i+j+1] + mul;
                digit[i+j+1] = sum%10;
                digit[i+j] += sum/10;
            }
        }

        string res = "";
        for (int x : digit) {
            if (!(res.empty() && x == 0)) res.push_back(x + '0');
        }
        return res.empty() ? "0" : res;
    }

};
