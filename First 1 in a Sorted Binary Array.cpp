// TC: O(log n) SC: O(1)
class Solution {
  public:
    int firstIndex(vector<int> &arr) {
        int left = 0;
        int right = arr.size()-1;
        int idx = -1;
        
        while(left <= right){
            int mid = left + (right-left)/2;
            
            if(arr[mid] == 1) {
                idx = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        
        return idx;
    }
};
