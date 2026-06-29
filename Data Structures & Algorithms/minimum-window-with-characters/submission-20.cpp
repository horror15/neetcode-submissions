class Solution {
public:
    bool contains(vector<int>v1, vector<int>v2){

        for(int i=0; i<v2.size(); i++){
            if(v1[i] > 0){
                if(v1[i] > v2[i]){
                    return false;
                }
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        if(s.size() < t.size()){
            return "";
        }
        int i=0, j=0, min_len=s.size(), start_index = -1;
        vector<int>st1(256, 0);
        vector<int>st2(256, 0);
        for(auto c:t){
            st1[c - 'A'] += 1;
        }
        
        while(j<s.size()){

            st2[s[j] - 'A'] += 1;
            while(contains(st1, st2)){
                if(min_len >= j-i+1){
                    start_index = i;
                    min_len = j-i+1;
                }
                st2[s[i] - 'A'] -= 1;
                i++;
            }
            j++;
        }
        if(start_index == -1){
            return "";
        }
        return s.substr(start_index, min_len);
    }
};
