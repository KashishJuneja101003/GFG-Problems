class Solution {
  public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(vector<int>& arr, int low, int high) {
        if(low >= high) return;
        
        int pivotIdx = partition(arr, low, high);
        
        quickSort(arr, low, pivotIdx-1);
        quickSort(arr, pivotIdx+1, high);
    }

  public:
    // Function that takes last element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int pivotIdx = low;
        
        for(int i=low; i<high; i++){
            if(arr[i] <= pivot){
                swap(arr[i], arr[pivotIdx]);
                pivotIdx++;
            }
        }
        
        swap(arr[pivotIdx], arr[high]);
        return pivotIdx;
    }
};
