class Solution {
  public:
    // Function to count the frequency of all elements from 1 to N in the array.
    vector<int> frequencyCount(vector<int>& arr) {
        
        vector<int> freq(arr.size(), 0);
        
        for(int i:arr){
            freq[i-1]++;
        }
        
        return freq;
    }
};
