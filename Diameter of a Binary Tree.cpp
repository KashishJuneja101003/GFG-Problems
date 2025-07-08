// Approach 1: Recursive TC: O(n) SC: O(n)
class Solution {
  public:
    int diam(Node* root, int& result){
        if(!root) return 0;
        
        int left = diam(root->left, result);
        int right = diam(root->right, result);
        
        result = max(result, left+right);
        return max(left, right) + 1;
    }
    
    int diameter(Node* root) {
        int result = 0;
        diam(root, result);
        
        return result;
    }
};
