// TC: O(log n) SC: O(1)
class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        int pos = -1;
        
        int n = arr.size();
        int left= 0;
        int right = n-1;
        
        while(left <= right){
            int mid = left + (right-left)/2;
            
            if(arr[mid] == k) return mid;
            else if(arr[mid] < k){
                pos = mid+1;
                left = mid+1;
            } else{
                pos = mid;
                right = mid-1;
            }
        }
        
        return pos;
    }
};
