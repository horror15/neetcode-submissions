class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>>s;
        vector<int>vec(temperatures.size(), -1);
        for(int i=0; i<temperatures.size(); i++){
            if(s.empty()){
                s.push({temperatures[i], i});
            } else if(temperatures[i] <= s.top().first){
                s.push({temperatures[i], i});
            } else {
                while(!s.empty() && s.top().first < temperatures[i]){
                    vec[s.top().second] = i-s.top().second;
                    s.pop();
                }
                s.push({temperatures[i], i});
            }
        }
        while(!s.empty()){
            vec[s.top().second] = 0;
            s.pop();
        }
        return vec;
    }
};
