class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        vector<int>out;

        
        for(int i=0; i<asteroids.size(); i++){
            if(asteroids[i] > 0){
                s.push(asteroids[i]);
            } else {
                bool exploded = false;
                while(!s.empty() && s.top()>0){
                    if(abs(asteroids[i]) > s.top()){
                        s.pop();
                        continue;
                    } else if(abs(asteroids[i]) == s.top()){
                        s.pop();
                        exploded  = true;
                        break;
                    } else {
                        exploded = true;
                        break;
                    } 
                }
                if(!exploded){
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