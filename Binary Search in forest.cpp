class Solution {
  public:
    int find_height(int tree[], int n, int k) {
        sort(tree, tree+n);
        
        int left = 0;
        int right = tree[n-1];
        
        while(left <= right){
            int mid = left + (right-left)/2;
            
            int curr = 0;
            for(int i=0; i<n; i++){
                int el = tree[i];
                if(el < mid) continue;
                curr += el - mid;
                
                if(curr > k) break;
            }
            
            if(curr == k) return mid;
            else if (curr > k) left = mid+1;
            else right = mid-1;
        }
        
        return -1;
    }
};
