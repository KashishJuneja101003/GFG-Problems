// TC: O(n * 2^n) SC: O(n)
class Solution {
  public:
    void getString(int n, string curr, vector<string>& ans){
        if(curr.size() == n){
            ans.push_back(curr); // O(n)
            return;
        }
        
        getString(n, curr+'0', ans);
        getString(n, curr+'1', ans);
    }
    
    vector<string> binstr(int n) {
        vector<string> ans;
        getString(n, "", ans);
        return ans;
    }
};
