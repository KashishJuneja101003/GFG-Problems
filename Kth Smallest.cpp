// Approach 1: Sorting TC: O(n logn) SC: O(1)
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());
        return arr[k-1];
    }
};

//Approach 2: MaxHeap TC: O(n log k) SC: O(k)
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> pq;
        
        for(int i:arr){
            pq.push(i);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};
