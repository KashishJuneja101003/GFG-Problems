class Solution {
  public:
    void getCombos(int n, int k, int last, vector<int> currCombo, vector<vector<int>>& combos){
        if(n < 0) return;
        if(k < 0) return;
        
        if(n == 0 && k == 0) {
            combos.push_back(currCombo);
            return;
        }
        
        
        for(int i=last+1; i<=9; i++){
            currCombo.push_back(i);
            getCombos(n-i, k-1, i, currCombo, combos);
            currCombo.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(int n, int k) {
        vector<vector<int>> combos;
        getCombos(n, k, 0, {}, combos);
        
        return combos;
    }
};
