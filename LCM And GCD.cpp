#include <vector>
#include <algorithm> // for std::gcd
using namespace std;

class Solution {
  public:
    vector<int> lcmAndGcd(int a, int b) {
        // Compute GCD using Euclid's algorithm (or STL function)
        int gcd = computeGCD(a, b);

        // Compute LCM using the relationship with GCD
        int lcm = (a / gcd) * b; // Division first to avoid overflow

        return {lcm, gcd};
    }

  private:
    // Function to compute GCD using Euclid's algorithm
    int computeGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};
