class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i=0, weight=0, count=0, j=people.size()-1;
        while(i<=j){
            weight = people[i] + people[j]; 
            if(weight > limit){
                j--;
                count++;
            } else{
                i++;
                j--;
                count++;
            }

        }
        return count;

    }
};