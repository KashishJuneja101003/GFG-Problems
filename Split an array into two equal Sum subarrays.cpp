// TC: O(n) SC: O(1)
class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        int right = n-1;
        
        int sum1 = 0;
        int sum2 = 0;
        
        while(left <= right){
            if(sum1 < sum2) {
                sum1 += arr[left];
                left++;
            } else {
                sum2 += arr[right];
                right--;
            }
        }
        
        return sum1 == sum2;
    }
};
