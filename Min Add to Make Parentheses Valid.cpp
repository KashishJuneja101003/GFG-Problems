class Solution {
  public:
    int minParentheses(string& s) {
        int ans = 0;
        stack<char> stk;
        
        for(char& c:s){
            if(c == '('){
                stk.push(c);
            } else{
                if(stk.empty()) ans++;
                else stk.pop();
            }
        }
        
        ans += stk.size();
        
        
        return ans;
    }
};
