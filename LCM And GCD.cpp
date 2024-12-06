class Solution {
  public:
    vector<int> lcmAndGcd(int a, int b) {
        // code here
        if(a==1 || b==1) return {a*b, 1};
        
        int lcm, gcd=1;
        for(int i=2; i <= a; i++){
            if(a%i == 0 && b%i==0) gcd = i;
        }
        
        lcm = (a*b)/gcd;
        
        return {lcm, gcd};
    }
};
