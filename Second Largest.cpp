class Solution {
  public:
    // Function returns the second
    // largest elements
    
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int fl = -1, sl = -1;
        
        for(int i:arr){
            if(i > fl){
                sl = fl; fl = i;
            }
            else if(i > sl && i != fl) sl = i;
        }
        
        return sl;
    }
};
