class Solution {
  public:
    int countBT(int h) {
        if(h <= 1) return 1;
        vector<int> dp(h+1,0);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2; i<=h; i++){
            dp[i] = dp[i-1]*(2*dp[i-2]+dp[i-1]);
        }
        
        return dp[h];
    }
};
