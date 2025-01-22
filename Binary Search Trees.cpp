class Solution {
  public:
    bool isBSTTraversal(vector<int>& arr) {
        // your code here
        for(int i=1; i<arr.size(); i++){
            if(arr[i-1] >= arr[i]){
                return false;
            }
        }
        
        return true;
    }
};
