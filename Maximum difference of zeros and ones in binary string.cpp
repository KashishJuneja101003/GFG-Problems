// TC: O(n) SC: (1)
class Solution {
public:
    int maxSubstring(string s) {
        int n = s.size();
        int curr = 0, best = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            int val = (s[i] == '0') ? 1 : -1;
            curr = max(val, curr + val);  // Kadane’s step
            best = max(best, curr);
        }
        
        return best;
    }
};
