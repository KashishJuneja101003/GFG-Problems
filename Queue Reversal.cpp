// Approach 1: Iterative TC: O(n) SC: O(n)
class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        stack<int> s;
        
        while(!q.empty()){
            s.push(q.front());
            q.pop();
        }
        
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
    }
};

// Approach 2: Recursive TC: O(n) SC: O(n) -> Recursive Stack
class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        if(q.empty()) return;
        
        int top = q.front();
        q.pop();

        // Reverse smaller queue
        reverseQueue(q);

        // Push element back at end
        q.push(top);
    }
};
