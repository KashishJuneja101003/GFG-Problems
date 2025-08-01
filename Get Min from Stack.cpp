class Solution {
  public:
    stack<pair<int, int>> stk;
    Solution() {
        // code here
        
    }

    // Add an element to the top of Stack
    void push(int x) {
        if(stk.empty()){
            stk.push({x, x});
        }
        else{
            int el = min(stk.top().second, x);
            stk.push({x, el});
        }
    }

    // Remove the top element from the Stack
        
    void pop() {
        if(!stk.empty()) stk.pop();
    }

        
    // Returns top element of the Stack
    int peek() {
        if(!stk.empty()) return stk.top().first;
        return -1;
    }
        

    // Finds minimum element of Stack
    int getMin() {
        if(!stk.empty()) return stk.top().second;
        return -1;
    }
};
