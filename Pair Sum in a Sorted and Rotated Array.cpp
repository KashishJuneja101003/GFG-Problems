class Solution {
  public:
    bool pairInSortedRotated(vector<int>& arr, int target) {
        int left = 0;
        int right = 0;
        int n = arr.size();
        
        for(int i=0; i<n-1; i++){
            if(arr[i] > arr[i+1]){
                right = i;
                left = (i+1)%n;
                break;
            }
        }
        
        if(left == 0 && right == 0){
            right = n-1;
        }
        
        while(left != right){
            int sum = arr[left]+arr[right];
            
            if(sum == target) return true;
            else if(sum < target) left = (left+1)%n;
            else right = (right-1+n)%n;
        }
        
        return false;
    }
};
