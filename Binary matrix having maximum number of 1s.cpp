class Solution {
  public:
    vector<int> findMaxRow(vector<vector<int>>& mat, int N) {
        int row = -1;
        int maxCount = 0;
        
        int j = N - 1;  // start at top-right
        for (int i = 0; i < N; i++) {
            // move left while we see 1s
            while (j >= 0 && mat[i][j] == 1) {
                j--;
                maxCount = N - (j + 1);
                row = i;
            }
        }
        
        if (row == -1) return {0, 0}; // no 1s at all
        return {row, maxCount};
    }
};
