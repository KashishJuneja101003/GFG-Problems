// TC: O(n) SC: O(1)
class Solution {
  public:
    void sort012(vector<int>& arr) {
        int zero = 0;
        int ones = 0;
        int twos = 0;
        
        for(int& i:arr){
            if(i == 0) zero++;
            else if(i == 1) ones++;
            else twos++;
        }
        
        int idx = 0;
        
        while(zero--) arr[idx++] = 0;
        while(ones--) arr[idx++] = 1;
        while(twos--) arr[idx++] = 2;
    }
};
