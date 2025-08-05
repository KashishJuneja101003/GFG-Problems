// TC: O(n) SC: O(1)
class Solution {
  public:
    bool isPalinSent(string &s) {
        int i=0, j=s.size()-1;
        
        while(i < j){
            char c1 = s[i];
            char c2 = s[j];
            
            if(!isalnum(c1)){
                i++; continue;
            }
            if(!isalnum(c2)){
                j--; continue;
            }
            
            if(tolower(c1) != tolower(c2)) return false;
            
            i++; j--;
        }
        
        return true;
    }
};
