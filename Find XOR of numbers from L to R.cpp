class Solution {
  public:
    int findXOR(int l, int r) {
        // complete the function here
        int xorResult = 0, n = r%4;
       
        if(n == 0) xorResult = r;
        else if(n == 1) xorResult = 1;
        else if(n == 2) xorResult = r+1;
        else if(n == 3) xorResult = 0;
        
        if(l != 0){
            n = (l-1)%4;
            if(n == 0) xorResult ^= l-1;
            else if(n == 1) xorResult ^= 1;
            else if(n == 2) xorResult ^= l;
            else if(n == 3) xorResult ^= 0;
        }
        return xorResult;
    }
};
