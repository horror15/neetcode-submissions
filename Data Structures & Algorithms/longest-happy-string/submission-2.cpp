class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string s = "";
        priority_queue<pair<int, int>>pq;
        // if condition a>0 or b>0 or c>0
        if (a>0){
            pq.push({a, 'a'});
        }
        if (b>0){
            pq.push({b, 'b'});
        }   
        if (c>0){
            pq.push({c, 'c'});
        }     
        while(!pq.empty()){
            auto first_top = pq.top();
            pq.pop();
            if(s.size() > 1 && s[s.size()-1] == s[s.size()-2] && first_top.second == s[s.size()-1]){
                if(pq.empty()) return s;
                auto second_top = pq.top();
                s +=  second_top.second;
                pq.pop();
                if (second_top.first > 1){
                    pq.push({second_top.first-1, second_top.second});
                }
                pq.push(first_top);
            } else{
                s += first_top.second;
                if(first_top.first > 1){
                    pq.push({first_top.first-1, first_top.second}); 
                }
                             
            }

        }
        return s;
    }
};