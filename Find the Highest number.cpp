class Solution {
  public:
    int findPeakElement(vector<int>& a) {
        int n = a.size();
        
        int left = 0;
        int right = n-1;
        
        int maxEl = 0;
        
        while(left <= right){
            int mid = left + (right-left)/2;
             
            maxEl= max(maxEl, a[mid]);
            
            if(mid != n-1 && a[mid] < a[mid+1]) {
                left = mid+1;
            }
            else{ 
                right = mid-1;
            }
        }
        
        return maxEl;
    }
};
