class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        stack<int>s;
        for(int i=0; i<k; i++){
            s.push(q.front());
            q.pop();
        }
        
        queue<int>ans;
        while(!s.empty()){
            ans.push(s.top());
            s.pop();
        }
        
        while(!q.empty()){
            ans.push(q.front());
            q.pop();
        }
        
        return ans;
    }
};
