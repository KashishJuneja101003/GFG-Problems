class Solution {
  public:
    int minValue(Node* root) {
        // Code here
        Node* temp = root;
        while(temp->left != nullptr){
            temp = temp->left;
        }
        
        return temp->data;
    }
};
