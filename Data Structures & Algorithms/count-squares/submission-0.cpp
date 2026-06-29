class CountSquares {
public:
    map<pair<int, int>, int>mp; 
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[{point[0], point[1]}] += 1; 
    }
    
    int count(vector<int> point) {
        int val=0;
        for(auto x:mp){
            pair<int, int> p = x.first;
            int a = abs(p.first - point[0]);
            int b = abs(p.second - point[1]);
            if(a>0 && b>0 && a==b){
                if(mp.find({point[0], p.second})!= mp.end() && mp.find({p.first, point[1]}) != mp.end()){
                    val += x.second*mp[{point[0], p.second}]*mp[{p.first, point[1]}];
                }
            }
        }
        return val;
    }
};
