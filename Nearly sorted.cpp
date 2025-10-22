class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        int n = arr.size();
    
        // Min Heap (by default priority_queue is max-heap, so we invert with greater<int>)
        priority_queue<int, vector<int>, greater<int>> minHeap;
    
        // Step 1: Insert first k+1 elements
        for (int i = 0; i <= k && i < n; i++) {
            minHeap.push(arr[i]);
        }
    
        int index = 0;
    
        // Step 2: Process the rest of the array
        for (int i = k + 1; i < n; i++) {
            arr[index++] = minHeap.top();
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    
        // Step 3: Pop remaining elements from heap
        while (!minHeap.empty()) {
            arr[index++] = minHeap.top();
            minHeap.pop();
        }
    }
};
