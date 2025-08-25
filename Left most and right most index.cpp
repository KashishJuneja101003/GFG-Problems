class Solution {
  public:
    
    int occurrence(vector<long long> v, long long x, string type){
        int left = 0;
        int right = v.size()-1;
        
        int idx = -1;
        
        while(left <= right){
            int mid = left + (right-left)/2;
            
            if(v[mid] == x) {
                idx = mid;
                if(type == "first"){
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            } else if(v[mid] < x) {
                left = mid+1;
            } else{
                right = mid-1;
            }
        }
        
        return idx;
    }
    
    
    pair<long, long> indexes(vector<long long> v, long long x) {
        return {occurrence(v, x, "first"), occurrence(v, x, "last")};
    }
};
