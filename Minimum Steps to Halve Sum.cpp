// TC: O(k log n) SC:	O(n)
class Solution {
public:
    int minOperations(vector<int>& arr) {
        priority_queue<double> pq;
        double total = 0;
        for (int x : arr) {
            pq.push(x);
            total += x;
        }

        double target = total / 2.0;
        double current = total;
        int ops = 0;

        while (current > target) {
            double top = pq.top(); pq.pop();
            double half = top / 2.0;
            current -= half;
            pq.push(half);
            ops++;
        }
        return ops;
    }
};
