/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int max_index = INT_MIN;
        int i=0, j=mountainArr.length()-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(mountainArr.get(mid) > mountainArr.get(mid-1) && mountainArr.get(mid) > mountainArr.get(mid+1)){
                max_index = mid;
                break;
            } else if(mountainArr.get(mid) > mountainArr.get(mid-1) && mountainArr.get(mid) < mountainArr.get(mid+1)){
                i = mid+1;
            } else {
                j = mid-1;
            }
        }
        int left = 0, right = max_index;
        while(left<=right){
            int mid = (left+right)/2;
            if(mountainArr.get(mid) == target){
                return mid;
            } else if(mountainArr.get(mid) < target){
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        left = max_index+1;
        right = mountainArr.length()-1;

        while(left<=right){
            int mid = (left+right)/2;
            if(mountainArr.get(mid) == target){
                return mid;
            } else if(mountainArr.get(mid) < target){
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return -1;

    }
};