class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i=0, j=k-1;
        vector<int>vec;
        while(j<arr.size()){
            if(j+1 < arr.size() && abs(arr[j+1]-x) < abs(arr[i]-x)){
                i++;
                j++;
            } else if (j+1 < arr.size() && arr[j+1] == arr[i]){
                i++;
                j++;
            } else {
                break;
            }
        }
        while(i<=j){
            vec.push_back(arr[i]);
            i++;
        }
        return vec;
    }
};