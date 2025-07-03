// Approach 1: TC: O(n) SC: O(k)
class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        if(q.size() < k) return q;
        
        stack<int> stk;
        for(int i=0; i<k; i++){
            stk.push(q.front());
            q.pop();
        }
        
        int size = q.size();
        
        while(!stk.empty()){
            q.push(stk.top());
            stk.pop();
        }
        
        for(int i=0; i<size; i++){
            q.push(q.front());
            q.pop();
        }
        
        return q;
    }
};
