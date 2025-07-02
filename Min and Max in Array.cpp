// Approach 1: TC: O(n) SC: O(1)
class Solution {
  public:
    pair<int, int> getMinMax(vector<int> arr) {
        int mini = 10e9;
        int maxi = 1;
        
        for(int i:arr){
            mini = min(mini, i);
            maxi = max(maxi, i);
        }
        
        return {mini, maxi};
        
    }
};

// Approach 2: Sorting TC: O(nlogn) SC: O(1)
/*
class Solution {
  public:
    pair<int, int> getMinMax(vector<int> arr) {
        sort(arr.begin(), arr.end());      
        return {arr[0], arr[arr.size()-1]};
        
    }
};
*/
