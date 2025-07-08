// Approach 1: Recursive TC: O(n) SC: O(h)
class Solution {
  public:
    void mirror(Node* node) {
        if(!node) return;
        
        swap(node->left, node->right);
        
        mirror(node->left);
        mirror(node->right);
    }
};
