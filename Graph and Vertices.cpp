class Solution {
  public:
    long long count(int n) {
        long long sum = n*(n-1)/2LL;
        return pow(2, sum);
    }
};
