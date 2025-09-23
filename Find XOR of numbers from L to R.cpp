// TC: O(n) SC: O(1)
class Solution {
  public:
    int findXOR(int l, int r) {
        int ans = 0;
            for(int i=l; i<=r; i++){
                ans ^= i;
            }

            return ans;
    }
};

// TC: O(1) SC: O(1)
class Solution {
  public:
    int calcXOR(int x){
        if(x%4 == 0) return x;
        if(x%4 == 1) return 1;
        if(x%4 == 2) return x+1;
        if(x%4 == 3) return 0;
    }
    
    int findXOR(int l, int r) {
        int xor1 = calcXOR(l-1);
        int xor2 = calcXOR(r);
        
        return xor1 ^ xor2;
    }
};
