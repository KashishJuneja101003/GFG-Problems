class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int n=arr.size();
        int currentMax = arr[n-1];
        
        vector<int> vec;
        for(int el = n-1; el >= 0; el--){
            if(arr[el] >= currentMax){
                vec.push_back(arr[el]);
                currentMax = arr[el];
            }
        }
        
        reverse(vec.begin(), vec.end());
        
        return vec;
    }
};
