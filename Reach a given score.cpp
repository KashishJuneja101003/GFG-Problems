// Recursion TC: O(3^n) SC: O(n)
class Solution {
  public:
    vector<int> scores = {3,5,10};
    
    long long getCombo(long long int target, int idx){
        if(target < 0) return 0;
        if(target == 0) return 1;

        long long ways = 0;
        
        for(int i=idx; i<3; i++){
            ways += getCombo(target-scores[i], i);
        }
        
        return ways;
    }
    
    long long int count(long long int n) {
        return getCombo(n, 0);
    }
};

// Memoization TC: O(n) SC: O(n)
class Solution {
  public:
    vector<int> scores = {3,5,10};
    
    ll getCombo(long long int target, int idx, vector<vector<ll>>& dp){
        if(target < 0) return 0;
        if(target == 0) return 1;
        if(dp[target][idx] != -1) return dp[target][idx];

        ll ways = 0;
        
        for(int i=idx; i<3; i++){
            ways += getCombo(target-scores[i], i, dp);
        }
        
        return dp[target][idx] = ways;
    }
    
    long long int count(long long int n) {
        vector<vector<ll>> dp(n+1, vector<ll>(3, -1));
        return getCombo(n, 0, dp);
    }
};
