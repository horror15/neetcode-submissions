class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        pair<int, string>p;
        p.first = timestamp;
        p.second = value;
        mp[key].push_back(p);
    }
    
    string get(string key, int timestamp) {
        if(mp[key].size() == 0){
            return "";
        }
        int sz = mp[key].size()-1;
        int i=0, j = sz;
        while(i<=j){
            int mid = i + (j-i)/2;
            if(mp[key][mid].first == timestamp){
                return mp[key][mid].second;
            } else if(mp[key][mid].first > timestamp){
                j = mid-1;
            } else {
                i = mid+1;
            }
        }
        if(i==0) return "";
        return mp[key][j].second;
    }
};
