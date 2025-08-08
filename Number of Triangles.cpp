// TC: O(n^3) SC: O(1)
class Solution {
  public:
    int numberOfTriangles(vector<vector<int>> &g, int n) {
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j || g[i][j] == 0) continue;
                for(int k=0; k<n; k++){
                    if(k == j || k == i || g[j][k] == 0 || g[k][i] == 0) continue;
                    count++;
                }
            }
        }
        
        return count/3;;
    }
};
