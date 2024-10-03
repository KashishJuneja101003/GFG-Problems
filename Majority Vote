class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        int n = nums.size();
        int one_third = n/3;
        
        vector<int> result;
        map<int, int> myMap;
        
        for(int i=0; i<n; i++){
            myMap[nums[i]]++;
        }
        
        
        for(auto& pair:myMap){
            if(pair.second > one_third) result.push_back(pair.first);
        }
        
        if(result.empty()) return {-1};
        
        return result;
    }
};
