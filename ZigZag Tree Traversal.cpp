// TC: O(n) SC: O(n)
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        bool rightToLeft = false;
        
        vector<int> order;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            int idx = order.size();
            
            for(int i=0; i<size; i++){
                Node* curr = q.front();
                q.pop();
                
                order.push_back(curr->data);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            
            if(rightToLeft){
                reverse(order.begin()+idx, order.end());
            }
            
            rightToLeft = !rightToLeft;
        }
        
        return order;
    }
};
