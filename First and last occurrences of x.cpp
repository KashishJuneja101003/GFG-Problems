class Solution {
  public:
    int occurrence(vector<int> v, int x, string type){
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
    
    vector<int> firstAndLast(int x, vector<int> &arr) {
        int first = occurrence(arr, x, "first");
        int last = occurrence(arr, x, "last");
        return (first == -1) ? vector<int>{-1} : vector<int>{first, last};
    }
};

