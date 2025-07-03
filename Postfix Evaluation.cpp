// TC: O(n) SC: O(n)
class Solution {
  public:
    int evaluate(vector<string>& arr) {
        stack<int> st;
        
        for(string& s:arr){
            if(isdigit(s[0]) || (s.size() > 1 && s[0] == '-')) {
                st.push(stoi(s));
            }
            else{
                int e2 = st.top(); st.pop();
                int e1 = st.top(); st.pop();
                int ans;
                
                if(s == "+") ans = e1 + e2;
                else if (s == "-") ans = e1 - e2;
                else if (s == "*") ans = e1 * e2;
                else if (s == "/") ans = e1 / e2;
                
                st.push(ans);
            }
        }
        
        return st.top();
    }
};
