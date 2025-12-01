// TC: O(n) SC: O(1)
class Solution {
  public:
    int cntPairs(vector<int>& arr, int k) {
        int n = arr.size();
        int count = 0;
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if((arr[i] ^ arr[j]) < k){
                    count++;
                }
            }
        }
        
        return count;
    }
};
