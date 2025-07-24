// TC: O(n) SC: O(1)
class Solution {
  public:
    string removeConsecutiveCharacter(string& s) {
        string str = "";
        char last = '#';
        
        for(char& c:s){
            if(c != last){
                last = c;
                str += c;
            }
        }
        
        return str;
    }
};
