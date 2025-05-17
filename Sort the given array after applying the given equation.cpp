class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        // code here
        vector<int> result;
        
        for(int x:arr){
            int el = x*x*A + x*B + C;
            result.push_back(el);
        }
        
        sort(result.begin(), result.end());
        
        return result;
    }
};
