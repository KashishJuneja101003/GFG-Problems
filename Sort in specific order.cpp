// TC: O(n log n) SC: O(n)
class Solution {
  public:
    void sortIt(vector<int>& arr) {
        vector<int> odds, evens;
        
        for(int& i:arr){
            if((i&1) == 0){
                evens.push_back(i);
            } else{
                odds.push_back(i);
            }
        }
        
        sort(odds.begin(), odds.end(), greater());
        sort(evens.begin(), evens.end());
        
        int idx = 0;
        for(int& i:odds){
            arr[idx++] = i;
        }
        for(int& i:evens){
            arr[idx++] = i;
        }
    }
};
