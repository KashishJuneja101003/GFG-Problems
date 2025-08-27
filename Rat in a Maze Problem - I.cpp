class Solution {
  public:
    int n;
    void getOrder(vector<vector<int>>& maze, int x, int y, string path, vector<string>& ans){
        if(x < 0 || y < 0 || x >= n || y >= n || maze[x][y] == 0){
            return;
        }
        
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }
        
        maze[x][y] = 0;
        
        getOrder(maze, x+1, y, path + 'D', ans);
        getOrder(maze, x, y-1, path + 'L', ans);
        getOrder(maze, x, y+1, path + 'R', ans);
        getOrder(maze, x-1, y, path + 'U', ans);
        
        maze[x][y] = 1;
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        n = maze.size();
        vector<string> ans;
        
        getOrder(maze, 0, 0, "", ans);
        
        return ans;
    }
};
