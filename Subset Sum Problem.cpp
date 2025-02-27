// Approach 1: Recursion O(2^n)
class Solution {
  public:
    bool func(vector<int>& arr, int target, int ind, int sum){
        if(ind < 0) {return sum == target;}
        
        if(arr[ind] > target) {
            return func(arr, target, ind-1, sum);
        }
        else if(arr[ind] == target || sum == target) {
            return true;
        }
        else{
            bool exclude = func(arr, target, ind-1, sum);
            bool include = func(arr, target, ind-1, sum + arr[ind]);
            
            return include || exclude;
        }
        
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        return func(arr, target, arr.size()-1, 0);
    }
};


// Approach 2: DP
