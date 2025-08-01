// TC: O(n) SC: O(1)
class Solution {
  public:
    vector<int> printUnsorted(vector<int>& arr) {
        int maxSoFar = arr[0];
        
        int start = 0;
        int end = -1;
        
        int minEl = INT_MAX;
        
        for(int i=0; i<arr.size(); i++){
            if(arr[i] >= maxSoFar){
                maxSoFar = arr[i];
            } else{
                minEl = min(minEl, arr[i]);
                end = i;
            }
        }
        
        if(end == -1) return {0, 0};
        
        // Get to know start location 
        while(start < end && arr[start] <= minEl) {
            start++;
        }
        
        return {start, end};
    }
};
