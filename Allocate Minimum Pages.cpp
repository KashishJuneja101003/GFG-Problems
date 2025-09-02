class Solution {
  public:
    bool isValid(vector<int> &arr, int k, int& maxVal){
        int curr = 0;
        int students = 1;
        for(int& i:arr){
            if(i > maxVal) return false;
            
            if(curr + i <= maxVal){
                curr += i;
            } else {
                students++;
                curr = i;
            }
        }
        
        return (students <= k);
    }
    
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        
        if(k > n) return -1;
        
        int ans = -1;
        int sum = 0;
        
        for(int& i:arr) sum += i;
        
        int left = 0;
        int right = sum;
        
        while(left <= right){
            int mid = left + (right-left)/2;
            
            if(isValid(arr, k, mid)){
                ans = mid;
                right = mid - 1;
            } else {
                left = mid+1;
            }
        }
        
        return ans;
    }
};
