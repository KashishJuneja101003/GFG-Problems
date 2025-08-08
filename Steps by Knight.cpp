// DFS TC: O(8^L) SC: O(n²)
class Solution {
  public:
    vector<vector<int>> directions = {{2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {-1, 2}, {1, -2}, {-1, -2}};
    
    bool isSafe(int x, int y, int n){
        return x >= 0 && y >= 0 && x < n && y < n;
    }
    
    void getSteps(int x, int y, int xt, int yt, int n, vector<vector<bool>>& visited, int currSteps, int& minSteps){
        // If reached target, update minSteps and return
        if(x == xt && y == yt){
            minSteps = min(minSteps, currSteps); return;
        }
        
        for(auto& dir:directions){
            int x_ = x + dir[0];
            int y_ = y + dir[1];
            
            if(isSafe(x_, y_, n) && !visited[x_][y_]){
                visited[x_][y_] = true;
                getSteps(x_, y_, xt, yt, n, visited, currSteps+1, minSteps);
                
                // Backtracking Step
                visited[x_][y_] = false;
            }
        }
        
    }
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Convert position from 1-based to 0-based indexing
        int x = knightPos[0] - 1; 
        int y = knightPos[1]-1; 
        int xt = targetPos[0]-1; 
        int yt = targetPos[1]-1;
        
        vector<vector<bool>> visited(n, vector<bool> (n, false));
        visited[x][y] = true;
        
        int minSteps = INT_MAX;
        
        getSteps(x, y, xt, yt, n, visited, 0, minSteps);
        
        return minSteps;
    }
};

// BFS TC: O(n^2) SC: O(n^2)
class Solution {
  public:
    vector<vector<int>> directions = {{2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {-1, 2}, {1, -2}, {-1, -2}};
    
    bool isSafe(int x, int y, int n){
        return x >= 0 && y >= 0 && x < n && y < n;
    }
    
    int getSteps(vector<int>& knightPos, vector<int>& targetPos, int n, vector<vector<bool>>& visited){
        int xi = knightPos[0];
        int yi = knightPos[1];
        int xt = targetPos[0];
        int yt = targetPos[1];
        
        // {steps, {x,y}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {xi, yi}});
        
        visited[xi][yi] = true;
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            int steps = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            
            // If reached target, return minSteps
            if(x == xt && y == yt){
                return steps;
            }
            
            for(auto& dir:directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                
                if(isSafe(x_, y_, n) && !visited[x_][y_]){
                    visited[x_][y_] = true;
                    q.push({steps+1, {x_, y_}});
                }
            }
        }
        
        return -1;
     }
     
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Convert position from 1-based to 0-based indexing
        knightPos[0]--;
        knightPos[1]--;
        targetPos[0]--;
        targetPos[1]--;
        
        vector<vector<bool>> visited(n, vector<bool> (n, false));
        
        return getSteps(knightPos, targetPos, n, visited);
    }
};
