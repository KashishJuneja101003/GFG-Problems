// Recursion TC: O(2^n) SC: O(n)
class Solution {
  public:
    int helper(vector<int>& height, int idx){
        if(idx == height.size()-1) return 0;
        
        int oneStep = helper(height, idx+1) + abs(height[idx+1] - height[idx]);
        
        int twoStep = INT_MAX;
        
        if(idx+2 < height.size())
            twoStep = helper(height, idx+2) + abs(height[idx+2] - height[idx]);
        
        return min(oneStep, twoStep);
    }
    int minCost(vector<int>& height) {
        return helper(height, 0);
    }
};

// Memoized TC: O(n) SC: O(n)
class Solution {
  public:
    int helper(vector<int>& height, int idx, int n, vector<int>& dp){
        if(idx == n-1) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int oneStep = helper(height, idx+1, n, dp) + abs(height[idx+1] - height[idx]);
        
        int twoStep = INT_MAX;
        
        if(idx+2 < height.size())
            twoStep = helper(height, idx+2, n, dp) + abs(height[idx+2] - height[idx]);
        
        return dp[idx] = min(oneStep, twoStep);
    }
    int minCost(vector<int>& height) {
        int n = height.size();
        
        vector<int> dp(n, -1);
        return helper(height, 0, n, dp);
    }
};
