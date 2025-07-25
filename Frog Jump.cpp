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

// Tabulation TC: O(n) SC: O(n)
class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, 0);
        
        for(int i=1; i<n; i++){
            int oneStep = dp[i-1] + abs(height[i-1] - height[i]);
            
            int twoStep = INT_MAX;
        
            if(i-2 >= 0)
                twoStep = dp[i-2] + abs(height[i-2] - height[i]);
                
            dp[i] = min(oneStep, twoStep);
        }
        
        return dp[n-1];
    }
};

// Space Optimisation in Tabulation TC: O(n) SC: O(1)
class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        int prev1 = 0;
        int prev2 = 0;
        
        
        for(int i=1; i<n; i++){
            int oneStep = prev1 + abs(height[i-1] - height[i]);
            
            int twoStep = INT_MAX;
        
            if(i-2 >= 0)
                twoStep = prev2 + abs(height[i-2] - height[i]);
                
            swap(prev1, prev2);
            prev1 = min(oneStep, twoStep);
        }
        
        return prev1;
    }
};
