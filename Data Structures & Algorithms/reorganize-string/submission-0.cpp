class Solution {
public:
    string reorganizeString(string s) {
        string st = "";
        vector<int>vec(26,0);
        priority_queue<pair<int, char>>pq;
        for (auto c: s){
            vec[c-'a'] += 1;
        }
        for (int i=0; i<vec.size(); i++){
            if(vec[i]!=0){
                pq.push({vec[i], 'a'+i});
            }
        }
        pair<int, char> prev;
        while(!pq.empty()){
            pair<int, char> top = pq.top();
            st += top.second;
            pq.pop();
            if(prev.first!=0){
                pq.push(prev);
            }
            prev = {top.first-1, top.second};
        }
        if(prev.first!=0){
            return "";
        } else {
            return st;
        }
    }
};