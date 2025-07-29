// Recursion TC: O(3^n) SC: O(n)
class Solution {
  public:
    int getMax(vector<vector<int>>& arr, int row, int last, int n){
        if(row >= n) return 0;
        
        // Get Max Point considering the last activity performed
        int act1 = 0;
        if(last != 0) act1 = arr[row][0] + getMax(arr, row+1, 0, n);
        
        int act2 = 0;
        if(last != 1) act2 = arr[row][1] + getMax(arr, row+1, 1, n);
        
        int act3 = 0;
        if(last != 2) act3 = arr[row][2] + getMax(arr, row+1, 2, n);
        
        return max(act1, max(act2, act3));
    }
    
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        
        if(n == 1) return max(arr[0][0], max(arr[0][1], arr[0][2]));
        
        return getMax(arr, 0, -1, n);
    }
};

// Memoized TC: O(4n) = O(n) SC: O(n)
class Solution {
  public:
    int getMax(vector<vector<int>>& arr, int row, int last, int n, vector<vector<int>>& dp){
        if(row >= n) return 0;
        if(dp[row][last] != -1) return dp[row][last];
        
        // Get Max Point considering the last activity performed
        int act1 = 0;
        if(last != 1) act1 = arr[row][0] + getMax(arr, row+1, 1, n, dp);
        
        int act2 = 0;
        if(last != 2) act2 = arr[row][1] + getMax(arr, row+1, 2, n, dp);
        
        int act3 = 0;
        if(last != 3) act3 = arr[row][2] + getMax(arr, row+1, 3, n, dp);
        
        return dp[row][last] = max(act1, max(act2, act3));
    }
    
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        
        if(n == 1) return max(arr[0][0], max(arr[0][1], arr[0][2]));
        
        vector<vector<int>> dp(n, vector<int> (4, -1));
        
        return getMax(arr, 0, 0, n, dp);
    }
};
