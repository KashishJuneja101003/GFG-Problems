// TC: O(n) SC: O(n)
class Solution {
  public:
    void reverse(stack<int> st, stack<int>& cloned){
        if(st.empty()) return;
        
        int val = st.top();
        st.pop();
        reverse(st, cloned);
        
        cloned.push(val);
    }
    
    void clonestack(stack<int> st, stack<int>& cloned) {
        reverse(st, cloned);
    }
};
