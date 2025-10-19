class Solution {
  public:
    vector<int> getKClosest(Node* root, int target, int k) {
        map<int, vector<int>> mp;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            
            int diff = abs(curr->data - target);
            mp[diff].push_back(curr->data);
            
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        
        vector<int> ans;
        for(auto& it:mp){
            vector<int> vec = it.second;
            sort(vec.begin(), vec.end());
            
            for(int i=0; i<vec.size(); i++){
                ans.push_back(vec[i]);
                if(ans.size() == k) return ans;
            }
        }
        
        return ans;
    }
};
