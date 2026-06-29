class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>s;
        for(auto ops:operations){
            if(ops == "+"){
                int a = s.top();
                s.pop();
                int  sum = a+s.top();
                s.push(a);
                s.push(sum);
            } else if(ops == "D"){
                int a = 2*s.top();
                s.push(a);
            } else if(ops == "C"){
                s.pop();
            } else{
                s.push(stoi(ops));
            }
        }
        int sum=0;
        while(!s.empty()){
            int a = s.top();
            sum += a;
            s.pop();
        }
        return sum;   
    }
};