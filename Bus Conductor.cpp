// TC: O(n log n) SC: O(1)
class Solution {
  public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        sort(chairs.begin(), chairs.end());
        sort(passengers.begin(), passengers.end());
        
        int n = chairs.size();
        int moves = 0;
        
        for(int i=0; i<n; i++){
            moves += abs(chairs[i]-passengers[i]);
        }
        
        return moves;
    }
};
