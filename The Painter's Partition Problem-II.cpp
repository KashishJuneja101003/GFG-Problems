class Solution {
  public:
    bool isValid(vector<int>& arr, int k, int maxTime){
        int painters = 1;
        int curr = 0;
        
        for(int& i:arr){
            if(i > maxTime) return false;
            
            if(curr + i <= maxTime){
                curr += i;
            } else {
                curr = i;
                painters++;
            }
        }
        
        return (painters <= k);
    }
    
    int minTime(vector<int>& arr, int k) {
        int sum = 0;
        for(int& i:arr) sum += i;
        
        int ans = -1;
        int left = 0;
        int right = sum;
        
        while(left <= right){
            int mid = left + (right-left)/2;
            
            if(isValid(arr, k, mid)){
                ans = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        
        return ans;
    }
};
