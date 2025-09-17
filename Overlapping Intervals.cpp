class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        
        int currStart = arr[0][0];
        int currEnd = arr[0][1];
        
        vector<vector<int>> intervals;
        
        for(auto& vec:arr){
            if(vec[0] <= currEnd){
                currEnd = max(currEnd, vec[1]);
            } else{
                intervals.push_back({currStart, currEnd});
                currStart = vec[0];
                currEnd = vec[1];
            }
        }

        intervals.push_back({currStart, currEnd});
        
        return intervals;
    }
};
