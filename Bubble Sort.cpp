class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        
        for(int j=0; j<n; j++){
            for(int i=0; i<n-j-1; i++){
                if(arr[i] > arr[i+1]){
                    swap(arr[i], arr[i+1]);
                }
            }
        }
    }
};
