// TC: O(log k) SC: O(k) for the heap + recursion stack O(h)
class Solution {
  public:
    void getKthSmallest(Node *root, int k, priority_queue<int>& pq){
        if(!root) return;
        
        pq.push(root->data);
        
        if(pq.size() > k) pq.pop();
        
        getKthSmallest(root->left, k, pq);
        getKthSmallest(root->right, k, pq);
    }
    
    int kthSmallest(Node *root, int k) {
        priority_queue<int> pq;
        getKthSmallest(root, k, pq);
        
        if(pq.size() < k) return -1;
        return pq.top();
    }
};
