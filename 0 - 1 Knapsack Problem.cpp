// Approach 1: Recursive TC: O(2^n)
class Solution {
  public:
    int KPK(int idx, int W, vector<int> &val, vector<int> &wt){
        if(idx == -1 || W == 0) return 0;
        
        int notPick = KPK(idx-1, W, val, wt);
        
        int pick = 0;
        if(wt[idx] <= W){
            pick = val[idx] + KPK(idx-1, W-wt[idx], val, wt);
        }
        
        return max(pick, notPick);
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        
        return KPK(n-1, W, val, wt);
    }
};

// Approach 2: Memoization TC: O(n*W) SC: O(n*W)
class Solution {
  public:
    int KPK(int idx, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
        if(idx == -1 || W == 0) return 0;
        
        if(dp[idx][W] != -1) return dp[idx][W];
        
        int notPick = KPK(idx-1, W, val, wt, dp);
        
        int pick = 0;
        if(wt[idx] <= W){
            pick = val[idx] + KPK(idx-1, W-wt[idx], val, wt, dp);
        }
        
        return dp[idx][W] = max(pick, notPick);
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int> (W+1, -1));
        return KPK(n-1, W, val, wt, dp);
    }
};
