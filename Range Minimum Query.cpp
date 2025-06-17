/* The functions which
builds the segment tree */

void buildSegTree(int arr[], int i, int l, int r, int segTree[]){
    if(l == r){
        segTree[i] = arr[r];
        return;
    }
    
    int mid = l + (r-l)/2;
    buildSegTree(arr, 2*i+1, l, mid, segTree);
    buildSegTree(arr, 2*i+2, mid+1, r, segTree);
    
    segTree[i] = min(segTree[2*i+1], segTree[2*i+2]);
}

int *constructST(int arr[], int n) {
    int* segTree = new int[4*n];
    
    buildSegTree(arr, 0, 0, n-1, segTree);
    return segTree;
}

/* The functions returns the
 min element in the range
 from a and b */
int getRangeMin(int st[], int start, int end, int i, int l, int r){
    if(l > end || r < start) return INT_MAX;
    
    if(l >= start && r <= end) return st[i];
    
    int mid = l + (r-l)/2;
    int min1 = getRangeMin(st, start, end, 2*i+1, l, mid);
    int min2 = getRangeMin(st, start, end, 2*i+2, mid+1, r);
    
    return min(min1, min2);
}

int RMQ(int st[], int n, int a, int b) {
    return getRangeMin(st, a, b, 0, 0, n-1);
}
