class Solution {
  public:
    int minCost(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int& i:arr) pq.push(i);
        
        int cost = 0;
        
        while(pq.size() != 1){
            int rope1 = pq.top();
            pq.pop();
            int rope2 = pq.top();
            pq.pop();
            
            int sum = rope1 + rope2;
            
            cost += sum;
            
            pq.push(sum);
        }
        
        return cost;
    }
};
