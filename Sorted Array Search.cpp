class Solution {
  public:
    // Function to find element in sorted array
    // arr: input array
    // k: element to be searched
    bool searchInSorted(vector<int> arr, int k) {

        // Your code here
        int start = 0, end = arr.size()-1;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(arr[mid] == k) return true;
            else if(arr[mid] < k) start = mid+1;
            else end = mid-1;
        }
        
        return false;
    }
};
