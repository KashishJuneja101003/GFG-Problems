// Approach 1: Using a Vector TC: O(n) SC: O(n)
class Solution {
  public:
   void deleteMid(stack<int>& s) {
        vector<int> vec;
        int size = s.size();
        int mid = size/2;
        
        for(int i=0; i<mid; i++){
            vec.push_back(s.top());
            s.pop();
        }
        
        s.pop();
        
        while(!vec.empty()){
            s.push(vec.back());
            vec.pop_back();
        }
    }
};
