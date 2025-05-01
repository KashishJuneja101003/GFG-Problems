class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        vector<int> nth_row(n);
        nth_row[0] = 1;
        
        for(int i=0; i<n-1; i++){
            nth_row[i+1] = nth_row[i] * (n-1-i)/(i+1);
        }
        
        return nth_row;
    }
};
