/*  Structure of a Binary Tree

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node* root) {
        queue<Node*> q;
        q.push(root);
        
        int maxWidth = 0;
        
        while(!q.empty()){
            int size = q.size();
            maxWidth = max(maxWidth, size);
            
            for(int i=0; i<size; i++){
                Node* curr = q.front();
                q.pop();
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        
        return maxWidth;
    }
};
