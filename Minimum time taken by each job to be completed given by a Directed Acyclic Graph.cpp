class Solution {
  public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, int size) {
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(n+1, 0);
        vector<int> Time(n);
        
        for(auto& vec:edges){
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            inDegree[v]++;
        }
        
        queue<int> q;
        int time_ = 1;
        
        for(int i=1; i<=n; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0; i<size; i++){
                int u = q.front();
                q.pop();
                
                Time[u-1] = time_;
                
                for(auto& v:adj[u]){
                    inDegree[v]--;
                    if(inDegree[v] == 0) q.push(v);
                }
            }
            time_++;
        }
        
        return Time;
    }
};
