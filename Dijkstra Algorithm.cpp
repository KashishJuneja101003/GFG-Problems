// Using Min-Heap
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Creating Adjacency List
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto& vec:edges){
            int n1 = vec[0];
            int n2 = vec[1];
            int wt = vec[2];
            
            adj[n1].push_back({n2, wt});
            adj[n2].push_back({n1, wt});
        }
        
        // Creating result vector and marking distance from src to src as 0
        vector<int> result(V, INT_MAX);
        result[src] = 0;
        
        // Creating priority queue to store the min distance found 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // The first min distance we've is from src to src
        pq.push({0, src});
        
        while(!pq.empty()){
            int minDist = pq.top().first;
            int curr = pq.top().second;
            pq.pop();
            
            // Explore neighbours of curr
            for(auto& p : adj[curr]){
                // Check if new distance is less than current distance to reach neighbour
                int neighbour = p.first;
                int newDist = minDist + p.second;
                
                if(newDist < result[neighbour]){
                    result[neighbour] = newDist;
                    pq.push({newDist, neighbour});
                }
            }
        }
        
        return result;
    }
};

// Using Set (More efficient than Min-Heap)
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Creating Adjacency List
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto& vec:edges){
            int n1 = vec[0];
            int n2 = vec[1];
            int wt = vec[2];
            
            adj[n1].push_back({n2, wt});
            adj[n2].push_back({n1, wt});
        }
        
        // Creating result vector and marking distance from src to src as 0
        vector<int> result(V, INT_MAX);
        result[src] = 0;
        
        // Creating set to store the min distance found 
        set<pair<int, int>>st;
        
        // The first min distance we've is from src to src
        st.insert({0, src});
        
        while(!st.empty()){
            int minDist = (*st.begin()).first;
            int curr = (*st.begin()).second;
            st.erase(st.begin());
            
            // Explore neighbours of curr
            for(auto& p : adj[curr]){
                // Check if new distance is less than current distance to reach neighbour
                int neighbour = p.first;
                int newDist = minDist + p.second;
                
                if(newDist < result[neighbour]){
                    if(result[neighbour] != INT_MAX){
                        auto it = st.find({result[neighbour], neighbour});
                        st.erase(it);
                    }
                    
                    result[neighbour] = newDist;
                    st.insert({newDist, neighbour});
                }
            }
        }
        
        return result;
    }
};
