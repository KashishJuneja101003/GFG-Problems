/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        map<int, int> mp;
        
        vector<int> order;
        
        while(!q.empty()){
            auto p = q.front(); q.pop();
            Node* curr = p.first;
            int dist = p.second;
            
            mp[dist] = curr->data;
            
            if(curr->left) q.push({curr->left, dist-1});
            if(curr->right) q.push({curr->right, dist+1});
        }
        
        for(auto& it:mp){
            order.push_back(it.second);
        }
        
        return order;
    }
};
