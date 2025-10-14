class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
        if(!root) return 0;
        
        int total = 0;
        if(root->data >= l && root->data <= r) total += root->data;
        total += nodeSum(root->left, l, r);
        total += nodeSum(root->right, l, r);
        
        return total;
    }
};
