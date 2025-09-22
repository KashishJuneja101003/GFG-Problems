// Brute-Force TC: O(n^2) SC: O(1)
class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 0);
        
        for(int i=0; i<n; i++){
            int minEl = INT_MAX;
            for(int j=i; j<n; j++){
                int winSize = j-i;
                minEl = min(minEl, arr[j]);
                ans[winSize] = max(ans[winSize], minEl);
            }
        }
        
        return ans;
    }
};
