class Solution {
  public:
    bool isPalindrome(string &s, int i, int j, vector<vector<int>>& dp){
        if(i >= j) return true;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] != s[j]) return dp[i][j] = false;
        
        return dp[i][j] = isPalindrome(s, i+1, j-1, dp);
    }
    
    string longestPalindrome(string &s) {
        int n = s.size();
        if(n == 1) return s;
        
        vector<vector<int>> dp(n, vector<int> (n, -1));
        
        int maxLen = -1;
        int startingPoint = -1;
        
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(j-i+1 > maxLen && isPalindrome(s, i, j, dp)){
                    maxLen = j-i+1;
                    startingPoint = i;
                }
            }
        }
        
        return s.substr(startingPoint, maxLen);
    }
};
