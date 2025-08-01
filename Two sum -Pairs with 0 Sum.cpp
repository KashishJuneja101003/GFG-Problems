class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        vector<bool> positive(1e5+1, false);
        vector<bool> negative(1e5+1, false);
        
        for(int i:arr){
            if(i == 0 && positive[i]) negative[0] = true;
            if(i >= 0) positive[i] = true;
            else negative[-i] = true;
        }
        
        vector<vector<int>> pairs;
        
        for(int i=1e5; i>=0; i--){
            if(positive[i] && negative[i]){
                pairs.push_back({-i, i});
            }
            
        }
        
        return pairs;
        
    }
};
