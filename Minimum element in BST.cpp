// Approach 1: TC: O(h) SC: O(1)
class Solution {
  public:
    int minValue(Node* root) {
        Node* temp = root;
        while(temp->left) temp = temp->left;
        return temp->data;
    }
};
