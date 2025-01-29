class Solution {
  public:
  int findMin(vector<int>& nums) {
        int n = nums.size(), st = 0, end = n-1, minEl = INT_MAX, idx=-1;
        
        while(st <= end){
            int mid = st+(end-st)/2;

            if(nums[mid] < minEl){
                minEl = nums[mid];
                idx = mid;
            }
            
            // Left Half Having Smaller Elements than Right Half
            if(nums[end] < nums[mid]){
                st = mid+1;
            }

            // Right Half Having Smaller Elements than Left Half
            else{
                end = mid-1;
            }
        }

        return idx;
    }
    
    int findKRotation(vector<int> &arr) {
        // Code Here
        
        return findMin(arr);
    }
};
