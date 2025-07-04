// Approach 1: TC: O(n) SC: O(n)
class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        stack<int> stk;
        int n = arr.size();
        vector<int> result(n);
        
        for(int i=n-1; i>=0; i--){
            while(!stk.empty() && stk.top() <= arr[i]) stk.pop();
            
            if(stk.empty()) result[i] = -1;
            else result[i] = stk.top();
            
            stk.push(arr[i]);
        }
        
        return result;
    }
};
