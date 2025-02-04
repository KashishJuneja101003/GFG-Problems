class Solution {
  public:
    int floorSqrt(int n) {
        int start = 1, end = n;
        int ans=0;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(mid*mid <= n){
                ans = mid;
                start = mid+1;
            } else{
                end = mid-1;
            }
        }
        
        return ans;
    }
};
