// Recursive: TC: O(2^n)
class Solution {
  public:
    bool checkSum(vector<int>& arr, int idx, int n, int currSum, int target){
        // If sum = target, return true
        if(currSum == target) return true;
        
        // If sum > target, return false
        // arr[i] is positive so we wont get back to target once it is passed
        // This is called pruning
        if(currSum > target) return false;
        
        // Out of bounds
        if(idx >= n) return false;
        
        // Case 1: arr[idx] > sum
        // Case 2: Exclude
        bool exclude = checkSum(arr, idx+1, n, currSum, target);
        
        // If arr[idx] < sum, include
        bool include = checkSum(arr, idx+1, n, currSum+arr[idx], target);
        
        return include || exclude;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        return checkSum(arr, 0, n, 0, sum);
    }
};

// Memoized TC: O(n*target)
class Solution {
  public:
    bool checkSum(vector<int>& arr, int n, int target, vector<vector<int>>& dp){
        if(target == 0) return true;
        
        // Out of bounds
        if(n < 0 || target < 0) return false;
        
        
        // Memoization step
        if(dp[n][target] != -1) return dp[n][target];
        
        // Case 1: arr[idx] > sum
        // Case 2: Exclude
        bool exclude = checkSum(arr, n-1, target, dp);
        
        // If arr[idx] < sum, include
        bool include = checkSum(arr, n-1, target-arr[n], dp);
        
        return dp[n][target] = include || exclude;
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
        
        return checkSum(arr, n-1, sum, dp);
    }
};

// Tabulation TC: O(n*target) SC: O(n*target)
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n+1, vector<bool> (sum+1, false));
        
        // sum = 0 is always achievable
        for(int i=0; i<=n; i++) dp[i][0] = true;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                bool exclude = dp[i-1][j];
                bool include = false;
                
                if(arr[i-1] <= j)
                    include = dp[i-1][j-arr[i-1]];
                    
                dp[i][j] = include || exclude;
            }
        }
        
        return dp[n][sum];
    }
};

// Space Optimization TC: O(n*target) SC: O(target)
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<bool> dp(sum+1, false);
        
        dp[0] = true;
        if(arr[0] <= sum) dp[arr[0]] = true;
        
        for(int i=1; i<n; i++){
            for(int j=sum; j>=0; j--){
                bool exclude = dp[j];
                bool include = false;
                
                if(arr[i] <= j)
                    include = dp[j-arr[i]];
                    
                dp[j] = include || exclude;
            }
        }
        
        return dp[sum];
    }
};
