// TC: O(q log n) SC: O(1)
class Solution {
  public:
    int BS(vector<int>& arr, int l, int r, int x, char type){
        int ans = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            
            if(arr[mid] == x){
                ans = mid;
                if(type == 'm'){
                    r = mid - 1;
                } else{
                    l = mid + 1;
                }
            } else if(arr[mid] < x){
                l = mid + 1;
            } else{
                r = mid - 1;
            }
        }
        
        return ans;
    }
    
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        
        for(auto& vec:queries){
            int l = vec[0];
            int r = vec[1];
            int x = vec[2];
            
            int minIdx = BS(arr, l, r, x, 'm');
            int maxIdx = BS(arr, l, r, x, 'M');
            
            if(minIdx == -1) {
                result.push_back(0);
                continue;
            }
            
            result.push_back(maxIdx - minIdx + 1);
        }
        
        return result;
    }
};
