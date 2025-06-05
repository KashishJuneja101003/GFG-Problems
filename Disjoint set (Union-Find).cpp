int find(int parent[], int i) {
    if(i == parent[i]){
        return i;
    }
    
    return parent[i] = find(parent, parent[i]);
}

void unionSet(int parent[], int x, int y) {
    int x_parent = find(parent, x);
    int y_parent = find(parent, y);
    
    // Union if x_parent and y_parent belongs to different sets
    if(x_parent != y_parent){
        parent[x_parent] = y_parent;
    }
}
