// Approach 1: Sorting TC: O(n logn) SC: O(1)
class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        sort(a.begin(), a.end());
        int minDiff = INT_MAX;
        int c1 = 0;
        int c2 = m-1;
        int n = a.size();
        
        while(c2 < n){
            int diff = a[c2]-a[c1];
            minDiff = min(minDiff, diff);
            c1++; c2++;
        }
        
        return minDiff;
    }
};
