class Solution {
  public:
    int nCr(int n, int r) {
        if (r > n) return 0;
        if (r > n - r) r = n - r; // use symmetry nCr = nC(n-r)
        
        long long res = 1;
        for (int i = 0; i < r; ++i) {
            res *= (n - i);
            res /= (i + 1);
        }
        return (int)res;
    }
};
