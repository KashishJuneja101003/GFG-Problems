// Recursive: TC: O(2^n)
class Solution {
  public:
    bool fun(vector<int>& arr, int currSum, int n, int target){
        if(n == 0) return false;
        if(currSum == target) return true;
        
        // Include
        bool include = fun(arr, currSum + arr[n-1], n-1, target);
        
        // Exclude
        bool exclude = fun(arr, currSum, n-1, target);
        
        return include || exclude;
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        return fun(arr, 0, arr.size(), sum);
    }
};

// Memoized TC: O(n*target)
class Solution {
public:
    bool fun(vector<int>& arr, int n, int target, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (n == 0) return false;
        
        // Memoization check
        if (dp[n][target] != -1) return dp[n][target];
        
        bool exclude = fun(arr, n - 1, target, dp);
        bool include = false;
        if (arr[n - 1] <= target)
            include = fun(arr, n - 1, target - arr[n - 1], dp);
        
        return dp[n][target] = include || exclude;
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return fun(arr, n, sum, dp);
    }
};
