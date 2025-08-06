// TC: O(n) SC: O(1)
class Solution {
  public:
    int maxLen(string& s) {
        int len = 0;
        int n = s.size();
        
        int open = 0;
        int close = 0;
        
        for(int i=0; i<n; i++){
            if(s[i] == '(') open++;
            else close++;
            
            if(open == close) {
                len = max(len, open*2);
            } else if (close > open) {
                open = 0; close = 0;
            }
        }
        
        open = 0; close = 0;
        
        for(int i=n-1; i>=0; i--){
            if(s[i] == '(') open++;
            else close++;
            
            if(open == close) {
                len = max(len, open*2);
            } else if (open > close) {
                open = 0; close = 0;
            }
        }
        
        return len;
    }
};
