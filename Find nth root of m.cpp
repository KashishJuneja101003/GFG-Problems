// TC: O(n log m) SC: O(1)
class Solution {
  public:
    int multiply(int num, int n){
        int ans = 1;
        for(int i=1; i<=n; i++) ans *= num;
        return ans;
    }
    
    int nthRoot(int n, int m) {
        int low = 1;
        int high = m;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            int mult = multiply(mid, n);
            
            if(mult == m) return mid;
            else if (mult < m){
                low = mid+1;
            } else{
                high = mid-1;
            }
        }
        
        return -1;
    }
};
