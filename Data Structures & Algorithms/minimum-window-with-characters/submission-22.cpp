class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) {
            return "";
        }
        int i=0, j=0, count=0, len = INT_MAX, start=-1;
        unordered_map<char, int>mp;
        for(const auto& s:t){
            mp[s] += 1;
        }
        while(j<s.size()){
            if(mp.count(s[j])){
                mp[s[j]] -= 1;
                if(mp[s[j]]>=0){
                    count++;
                }
            }
            while(count==t.size()){
                if(j-i+1 < len){
                    len = j-i+1;
                    start = i;
                }
                if(mp.count(s[i])){
                    mp[s[i]]++;
                    if(mp[s[i]]>0){
                        count--;
                    }
                }
                i++;
            }
            j++;
        }
        if(len==INT_MAX){
            return "";
        }
        return s.substr(start, len);
    }
};
