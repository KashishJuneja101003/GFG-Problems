vector<vector<int>> directions = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
int dir = 0;

void face(char d){
    if(dir == 0) {
        if(d == 'L') dir = 2;
        else dir = 1;
    } else if (dir == 1){
        if(d == 'L') dir = 0;
        else dir = 3;
    } else if (dir == 2){
        if(d == 'L') dir = 3;
        else dir = 0;
    } else {
        if(d == 'L') dir = 1;
        else dir = 2;
    }
}

string isCircular(string path) {
    int x = 0;
    int y = 0;
    
    for(char& c:path){
        if(c == 'G'){
            x += directions[dir][0];
            y += directions[dir][1];
        } else{
            face(c);
        }
    }
    
    if(x == 0 && y == 0) return "Circular";
    return "Not Circular";
}

// D L R U
