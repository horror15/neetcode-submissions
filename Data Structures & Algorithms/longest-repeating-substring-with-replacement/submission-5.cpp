class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0, max_freq = 0, j=0;
        vector<int>vec(26, 0);
        int count=0;
        while(j<s.size()){
            vec[s[j]-'A'] += 1;
            max_freq = max(max_freq, vec[s[j]-'A']);
            if((j-i+1)-max_freq > k){
                vec[s[i]-'A'] -= 1;
                i++;
            }
            count = max(count, j-i+1);
            j++;
        }
        return count;
    }
};
