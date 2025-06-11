class Solution {
  public:
    void generateSubsets(vector<int>& arr, vector<vector<int>>& subSets, vector<int> currSet, int idx){
        // Base Case
        if(idx == arr.size()){
            subSets.push_back(currSet);
            return;
        }
        
        // Taken
        currSet.push_back(arr[idx]); 
        generateSubsets(arr, subSets, currSet, idx+1);
        
        // Not Taken
        currSet.pop_back();
        generateSubsets(arr, subSets, currSet, idx+1);
    }
    
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> subSets;
        
        generateSubsets(arr, subSets, {}, 0);
        
        sort(subSets.begin(), subSets.end());
        
        return subSets;
    }
};
