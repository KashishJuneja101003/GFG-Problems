class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
        int mask;
        
        // Get ith bit
        mask = 1<<(i-1);
        if((num & mask) == 0) cout<<0;
        else cout<<1;
        
        // Set ith bit
        cout<<" "<<(num | mask);
        
        // Clear ith bit
        mask = ~mask;
        cout<<" "<<(num & mask);
    }
};
