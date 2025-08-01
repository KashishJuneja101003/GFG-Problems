// TC: O(n) SC: O(1)
class Solution {
  public:
    // #define ll long long
    int countStrings(int n) {
        if(n == 1) return 2;
        if(n == 2) return 3;
        
        int first = 2;
        int second = 3;
        
        for(int i=3; i<=n; i++){
            int curr = first+second;
            first = second;
            second = curr;
        }
        
        return second;
    }
};
