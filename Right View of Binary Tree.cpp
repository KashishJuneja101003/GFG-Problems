// TC: O(n) SC: O(n)
class Solution {
  public:
    vector<int> rightView(Node *root) {
        if(!root) return {};
        
        queue<pair<Node*, int>> q;
        vector<int> result;
        
        q.push({root, 0});
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0; i<size; i++){
                Node* curr = q.front().first;
                int level = q.front().second;
                q.pop();
                
                if(curr->left) q.push({curr->left, level+1});
                if(curr->right) q.push({curr->right, level+1});
                
                if(i == size-1) result.push_back(curr->data);
            }
            
        }
        
        return result;
    }
};
