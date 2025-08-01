class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int maxSum = INT_MIN;
        int currSum = 0;
        
        for(int i:arr){
            currSum += i;
            maxSum = max(maxSum, currSum);
            
            if(currSum < 0) currSum = 0;
        }
        
        return maxSum;
    }
};
