class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        int n = arr.size();
        if(n == 1) return;
        
        int i=0;
        int j=n-1;
        
        while(i < j){
            swap(arr[i], arr[j]);
            i++; j--;
        }
    }
};
