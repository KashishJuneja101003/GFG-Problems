// TC: O(n) SC: O(n)
class Solution {
  public:
    bool findPair(vector<int> &arr, int x) {
        unordered_set<int> st;
        
        for(int& b:arr){
            int ans1 = b+x;
            int ans2 = b-x;
            
            if(st.find(ans1) != st.end()) return true;
            else if(st.find(ans2) != st.end()) return true;
            else st.insert(b);
        }
        
        return false;
    }
};
