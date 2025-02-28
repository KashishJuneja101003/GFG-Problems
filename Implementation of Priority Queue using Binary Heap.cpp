class Solution {
  public:
    int extractMax() {
        int ans = H[0];
        H[0] = H[s];
        shiftDown(0);
        s--;
        return ans;
    }
};
