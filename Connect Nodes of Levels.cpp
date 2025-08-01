/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */

class Solution {
  public:
    // Function to connect nodes at same level.
    Node* connect(Node* root) {
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0; i<size; i++){
                Node* curr = q.front(); q.pop();
                
                if(i == size-1) curr->nextRight = nullptr;
                else curr->nextRight = q.front();
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        
        return root;
    }
};
