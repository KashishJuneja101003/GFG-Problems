// TC: O(n × m × log(n × m)) SC: O(m x n)
class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto& vec:mat){
            for(int& x:vec){
                pq.push(x);
            }
        }
        
        for(int i=1; i<k; i++){
            pq.pop();
        }
        
        return pq.top();
    }
};

