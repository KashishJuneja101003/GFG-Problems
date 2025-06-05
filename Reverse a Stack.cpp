// Using 2 stacks; O(n) auxiliary space
/*
class Solution {
  public:
    void Reverse(stack<int> &st) {
        if(st.size() == 0){
            return;
        }
        
        int val = st.top();
        st.pop();
        
        Reverse(st);
        
        stack<int> temp;
        
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        
        st.push(val);
        
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }
};
*/

// O(1) Auxiliary Space
class Solution {
  public:
    void insertAtBottom(stack<int> &st, int& bottomValue){
        if(st.empty()){
            st.push(bottomValue);
            return;
        }
        
        int top = st.top();
        st.pop();
        
        insertAtBottom(st, bottomValue);
        
        st.push(top);
    }
    void Reverse(stack<int> &st) {
        if(st.size() == 0){
            return;
        }
        
        int val = st.top();
        st.pop();
        
        Reverse(st);
        insertAtBottom(st, val);
    }
};
