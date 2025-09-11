class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;
        if (arr[0] == 0) return -1;
    
        int jumps = 0, farthest = 0, current_end = 0;
    
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + arr[i]);
    
            // If we can't move forward
            if (i == farthest) return -1;
    
            // If we reach the end of the current jump range
            if (i == current_end) {
                jumps++;
                current_end = farthest;
                if (current_end >= n - 1) return jumps;
            }
        }
    
        return -1;
    }

};
