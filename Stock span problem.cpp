class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        vector<int> spans;
        stack<int> stk;
        
        for(int i=0; i<arr.size(); i++){
            while(!stk.empty() && arr[stk.top()] <= arr[i]) stk.pop();
            
            if(stk.empty()) spans.push_back(i+1);
            else spans.push_back(i-stk.top());
            
            stk.push(i);
        }
        
        return spans;
    }
};
