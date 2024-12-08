class Solution {
  public:

    int findFloor(vector<int>& arr, int k) {
        int start = 0, end = arr.size()-1, result = -1;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(arr[mid] <= k){
                result = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        
        return result;
    }
};
