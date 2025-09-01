class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        
        int left = 0;
        int right = n-1;
        
        while(left < right){
            int mid = left + (right - left)/2;
            
            if(arr[mid] > arr[right]) left = mid+1;
            else right = mid;
        }
        
        return right;
    }
};
