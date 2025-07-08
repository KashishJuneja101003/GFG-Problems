// Approach 1: Level Order Traversal TC: O(n) SC: O(n)
class Solution {
  public:
    vector<int> topView(Node *root) {
        queue<pair<Node*, int>> q; // {Node, Horizontal Distance}
        map<int, int> mp; // Horizontal Distance -> Node->data
        
        q.push({root, 0});
        
        while(!q.empty()){
            Node* curr = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            if(mp.find(dist) == mp.end()) mp[dist] = curr->data;
            
            
            if(curr->left) q.push({curr->left, dist-1});
            if(curr->right) q.push({curr->right, dist+1});
        }
        
        
        vector<int> result;
        for(auto& it:mp){
            result.push_back(it.second);
        }
        return result;
    }
};
