// Approach 1: Recursive TC: O(n) SC: O(n) (Risk of stack overflow if depth > 10^4)
class Solution {
  public:
    int height(Node* node) {
        if(!node) return 0;
        if(!node->left && !node->right) return 0;
        
        int left = height(node->left);
        int right = height(node->right);
        
        return 1 + max(left, right);
    }
};

// Approach 2: Iterative TC: O(n) SC: O(n)
class Solution {
  public:
    int height(Node* node) {
        if(!node) return 0;
        
        int level = 0;
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                Node* curr = q.front(); q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            
            level++;
        }
        
        return level-1;
    }
};
