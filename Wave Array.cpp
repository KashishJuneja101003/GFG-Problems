class Solution {
  public:
    // arr: input array
    // Function to sort the array into a wave-like array.
    void convertToWave(vector<int>& arr) {
        // code here
        int n=arr.size();
        for(int i=0; i<n-1; i+=2){
            if(i+1 >= n){
                break;
            }
            
            swap(arr[i], arr[i+1]);
        }
    }
};
