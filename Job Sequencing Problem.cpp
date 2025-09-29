class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = profit.size();
        
        vector<pair<int, int>> tasks(n);
        
        for(int i=0; i<n; i++){
            tasks[i] = {deadline[i], profit[i]};
        }
        
        sort(tasks.begin(), tasks.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0; i<n; i++){
            int deadline = tasks[i].first;
            int profit = tasks[i].second;
            
            if(pq.size() < deadline){
                pq.push(profit);
            } else {
                if(pq.top() < profit){
                    pq.pop();
                    pq.push(profit);
                }
            }
        }
        
        int jobs = pq.size();
        int maxProfit = 0;
        
        while(!pq.empty()){
            maxProfit += pq.top();
            pq.pop();
        }
        
        
        return {jobs, maxProfit};
    }
};
