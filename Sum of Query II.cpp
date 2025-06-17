class Solution {
  public:
    vector<int> segmentTree;
    
    void buildSegTree(int arr[], int idx, int l, int r, int n){
        if(l == r) {
            segmentTree[idx] = arr[r];
            return;
        }
        
        int mid = l + (r-l)/2;
        buildSegTree(arr, 2*idx+1, l, mid, n);
        buildSegTree(arr, 2*idx+2, mid+1, r, n);
        segmentTree[idx] = segmentTree[2*idx+1] + segmentTree[2*idx+2];
    }
    
    int getRangeSum(int start, int end, int i, int l, int r){
        // Out of bound
        if(l > end || r < start) return 0;
        
        // Inside range
        if(l >= start && r <= end) return segmentTree[i];
        
        // Overlapping
        int mid = l + (r-l)/2;
        
        int left = getRangeSum(start, end, 2*i+1, l, mid);
        int right = getRangeSum(start, end, 2*i+2, mid+1, r);
        
        return left+right;
    }
    
    vector<int> querySum(int n, int arr[], int q, int queries[]) {
        segmentTree.resize(4*n, 0);
        
        buildSegTree(arr, 0, 0, n-1, n);
        
        vector<int> rangeSum;
        for(int i=0; i<2*q; i+=2){
            int start = queries[i]-1;
            int end = queries[i+1]-1;
            rangeSum.push_back(getRangeSum(start, end, 0, 0, n-1));
        }
        
        return rangeSum;
    }
};
