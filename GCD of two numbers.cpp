// TC: O(n) SC: O(1)
class Solution {
  public:
    int gcd(int a, int b) {
        while(a != 0 && b != 0){
            if(a > b) a %= b;
            else b %= a;
        }
        
        if(a == 0) return b;
        if(b == 0) return a;
    }
};

// Assumed that a > b; TC: O(n) SC: O(n) - recursive stack
class Solution {
  public:
    int getGCD(int a, int b){
        if(b == 0) return a;
        
        return getGCD(b, a%b);
    }
    
    int gcd(int a, int b) {
        return getGCD(a, b);
    }
};
