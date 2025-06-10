class Solution {
  public:
    void move(int i, int j, vector<vector<int>>& maze, vector<string>& paths, string currentPath){
        if(maze[i][j] == 0) return;
        
        int n = maze.size();
        if(i == n-1 && j == n-1){
            paths.push_back(currentPath); return;
        }
        
        maze[i][j] = 0;
        
        if(i-1 >= 0) move(i-1, j, maze, paths, currentPath+'U');
        
        if(i+1 < n) move(i+1, j, maze, paths, currentPath+'D');
        
        if(j-1 >= 0) move(i, j-1, maze, paths, currentPath+'L');
        
        if(j+1 < n) move(i, j+1, maze, paths, currentPath+'R');
        
        maze[i][j] = 1;
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> paths;
        move(0, 0, maze, paths, "");
        sort(paths.begin(), paths.end());
        return paths;
    }
};
