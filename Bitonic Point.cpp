class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
        int n = arr.size();
        int left = 0, right = n-1;
        int bitonicPoint = -1;
        while(left <= right){
            int mid = left + (right-left)/2;
            
            if(arr[mid] < arr[mid+1]) {
                left = mid+1;
            }
            else if (arr[mid] > arr[mid+1]) {
                bitonicPoint = arr[mid];
                right = mid-1;
            }
        }
        
        return bitonicPoint;
    }
};
