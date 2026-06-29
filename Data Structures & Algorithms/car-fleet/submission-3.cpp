class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>>vec;
        stack<float>s;
        int fleet = 0;
        for(int i=0; i<position.size(); i++){
            pair<int, int>p;
            p.first = position[i];
            p.second = speed[i];
            vec.push_back(p);
        }
        sort(vec.begin(), vec.end());
        for(int i=0; i<vec.size(); i++){
            float time = (float)(target-vec[i].first)/vec[i].second;
            s.push(time);
        }

        while(!s.empty()){
            
            float time = s.top();
            s.pop();
            if(s.empty()){
                fleet+=1;
            }else if(time<s.top()){
                fleet+=1;
            } else{
                while(!s.empty() && time>=s.top()){
                    s.pop();
                }
                fleet+=1;
            }
        }
        return fleet;

    }
};
