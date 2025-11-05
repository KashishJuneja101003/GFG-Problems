class Solution {
  public:
    bool isPerfectSquare(int x) {
        int r = sqrt(x);
        return r * r == x;
    }

    int minSquares(int n) {
        if (isPerfectSquare(n))
            return 1;

        for (int i = 1; i * i <= n; ++i)
            if (isPerfectSquare(n - i * i))
                return 2;

        int m = n;
        while (m % 4 == 0)
            m /= 4;
        if (m % 8 == 7)
            return 4;

        return 3;
    }
};
