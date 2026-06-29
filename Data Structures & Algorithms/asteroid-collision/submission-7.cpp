class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        vector<int>out;


        
        for(int i=0; i<asteroids.size(); i++){
            if(asteroids[i] > 0){
                s.push(asteroids[i]);
            } else {
                if(s.empty() || s.top()<0){
                    s.push(asteroids[i]);
                    continue;
                }
                while(!s.empty()){
                    if(s.top()>0 && abs(asteroids[i]) > s.top()){
                        s.pop();
                    } else if(s.top() > 0 && abs(asteroids[i]) == s.top()){
                        s.pop();
                        asteroids[i] = 0;
                        break;
                    } else {
                        if(s.top()<0){
                            s.push(asteroids[i]);
                        }
                        break;
                    } 
                }
                if(s.empty() && asteroids[i]!=0){
                    s.push(asteroids[i]);
                }
            }
        }
        while(!s.empty()){
            out.push_back(s.top());
            s.pop();
        }
        reverse(out.begin(), out.end());
        return out;
    }
};