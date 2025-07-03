// Approach 1: Iterative TC: O(n) SC: O(n)
class Solution {
  public:
    queue<int> reverseQueue(queue<int> &q) {
        stack<int> stk;
        while(!q.empty()){
            stk.push(q.front());
            q.pop();
        }
        
        while(!stk.empty()){
            q.push(stk.top());
            stk.pop();
        }
        
        return q;
    }
};

// Approach 2: Recursive TC: O(n) SC: O(n)
class Solution {
  public:
    void reverse(queue<int> &q){
        if(q.size() == 0) return;
        int val = q.front();
        q.pop();
        
        reverse(q);
        q.push(val);
    }
    
    queue<int> reverseQueue(queue<int> &q) {
        reverse(q);
        return q;
    }
};
