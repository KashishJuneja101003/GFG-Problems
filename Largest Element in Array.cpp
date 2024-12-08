class Solution {
  public:
    int largest(vector<int> &arr) {
        int greatest = INT_MIN;
        for(int i:arr)
            greatest = max(greatest, i);
        return greatest;
    }
};
