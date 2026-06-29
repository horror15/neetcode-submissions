class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size() / groupSize;
        int start;
        if((hand.size() % groupSize)!=0) return false;
        map<int, int> mp;
        for(int i=0; i<hand.size(); i++){
            mp[hand[i]] += 1;
        }
        if(groupSize > mp.size()) return false;
        for(int i=0; i<n; i++){
            auto it = mp.begin();
            start = it->first;
            for(int j=0; j<groupSize; j++){
                int next = start+j;
                if(mp.find(next) == mp.end()){
                   return false;
                } 
                mp[next]--;
                if(mp[next] == 0){
                    mp.erase(next);
                }
            }
        }
        return true;
    }
};
