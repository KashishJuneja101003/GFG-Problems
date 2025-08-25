/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

class Solution {
  public:
    int maxLevelSum(Node* root) {
        queue<Node*> q;
        int maxSum = INT_MIN;
        
        q.push(root);
        
        while(!q.empty()){
            int currSum = 0;
            int size = q.size();
            
            for(int i=0; i<size; i++){
                Node* node = q.front(); q.pop();
                currSum += node->data;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            maxSum = max(maxSum, currSum);
        }
        
        return maxSum;
    }
};
