// TC: O(n) SC: O(1)
class Solution {
  public:
    bool stringStack(string &pat, string &tar) {
        int n1 = pat.size();
        int n2 = tar.size();
        
        if(n2 > n1) return false;
        
        int i = n1-1;
        int j = n2-1;
        
        while(i >= 0 && j >= 0){
            if(pat[i] == tar[j]) {
                i--;
                j--;
            } else{
                i-=2;
            }
        }
        
        return j < 0;
    }
};
