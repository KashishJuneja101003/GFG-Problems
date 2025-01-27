class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        int floorX = -1, ceilX = -1;
        
        for(int i:arr){
            floorX = (i <= x && i > floorX) ? i : floorX;
            ceilX = (i >= x && (i < ceilX || ceilX == -1)) ? i : ceilX;
        }
        return {floorX, ceilX};
    }
};
