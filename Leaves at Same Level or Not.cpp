// TC: O(n) SC: O(n)
class Solution {
  public:
    bool check(Node *root) {
        queue<pair<Node*, int>>q;
        q.push({root, 0});
        
        int leafLevel = -1;
        
        while(!q.empty()){
            Node* curr = q.front().first;
            int level = q.front().second;
            q.pop();
            
            // If leaf nodes is found
            if(!curr->left && !curr->right){
                if(leafLevel == -1){
                    leafLevel = level;
                } else if(leafLevel != level){
                    return false;
                }
            }
            
            if(curr->left) q.push({curr->left, level+1});
            if(curr->right) q.push({curr->right, level+1});
        }
        
        return true;
    }
};
