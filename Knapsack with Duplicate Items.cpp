// Memoized TC: O(n*W) SC: O(n*W)
class Solution {
  public:
    int KPK(vector<int>& val, vector<int>& wt, int W, int n, vector<vector<int>>& dp){
        if(n == 0 || W == 0) return 0;
        
        if(dp[n][W] != -1) return dp[n][W];
        
        int exclude = KPK(val, wt, W, n-1, dp);
        
        int include = 0;
        if(wt[n-1] <= W){
            include = val[n-1] + KPK(val, wt, W-wt[n-1], n, dp);
        }
        
        return dp[n][W] = max(include, exclude);
    }
    
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> dp (n+1, vector<int> (capacity+1, -1));
        
        return KPK(val, wt, capacity, n, dp);
    }
};
