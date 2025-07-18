// Memoized: TC: O(n*target) SC: O(n*target)
class Solution {
  public:
    int fun(vector<int>& arr, int n, int target, vector<vector<int>>& dp){
        if(n == 0) {
            return (target == 0) ? 1 : 0;
        }
        
        if(dp[n][target] != -1) return dp[n][target];
        
        int exclude = fun(arr, n-1, target, dp);
        
        int include = 0;
        
        if(arr[n-1] <= target) include = fun(arr, n-1, target-arr[n-1], dp);
        
        return dp[n][target] = include + exclude;
    }
    
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        
        vector<vector<int>> dp (n+1, vector<int> (target+1, -1));
        
        return fun(arr, n, target, dp);
    }
};
