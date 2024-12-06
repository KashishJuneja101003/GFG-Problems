class Solution {
  public:
    vector<int> lcmAndGcd(int a, int b) {
        // code here
        
        int lcm, gcd=1;
        for(int i=2; i <= min(a, b); i++){
            if(a%i == 0 && b%i==0) gcd = i;
        }
        
        lcm = (a/gcd)*b; //To avoid overflow
        
        return {lcm, gcd};
    }
};
