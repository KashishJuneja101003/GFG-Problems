// User function Template for C++

/* Node of the binary search tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node *flattenBST(Node *root) {
        if(root == nullptr) return nullptr;
        
        Node* leftSubTree = root->left;
        Node* rightSubTree = root->right;
        
        
        Node* headLeft = flattenBST(leftSubTree);
        root->left = nullptr;
        if(headLeft == nullptr){
            headLeft = root;
        } else{
            Node* temp = headLeft;
            while(temp->right != nullptr){
                temp = temp->right;
            }
            temp->right = root;
        }
        
        Node* nodeRight = flattenBST(rightSubTree);
        root->right = nodeRight;
        
        return headLeft;
    }
};
