class Solution {
  public:
    int knapsackHelper(vector<int> &wt, vector<int> &val, int W, int n, vector<vector<int>> &dp){
        if(n == 0 || W == 0){
            return 0;
        }
        
        if(dp[n][W] != -1) return dp[n][W];
        
        if(wt[n-1] <= W){
            int include = val[n-1] + knapsackHelper(wt, val, W-wt[n-1], n-1, dp);
            int exclude = knapsackHelper(wt, val, W, n-1, dp);
            
            dp[n][W] = max(include, exclude);
        } else{
            dp[n][W] = knapsackHelper(wt, val, W, n-1, dp);
        }
        
        return dp[n][W];
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=wt.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
        return knapsackHelper(wt, val, W, n, dp);
    }
};
