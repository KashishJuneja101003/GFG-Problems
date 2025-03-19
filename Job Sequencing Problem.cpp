bool comparator(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}

class Solution {
  public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        
        int n = id.size();
        vector<pair<int, int>> profit_deadline(n);
        
        for(int i = 0; i < n; i++){
            profit_deadline[i] = {profit[i], deadline[i]};
        }
        
        sort(profit_deadline.begin(), profit_deadline.end(), comparator);
        
        int maxDeadline = *max_element(deadline.begin(), deadline.end());
        
        vector<int> jobAssigned(maxDeadline+1, -1);
        
        for(auto pair:profit_deadline){
            int idx = pair.second;
            
            while(idx > 0 && jobAssigned[idx] != -1){
                idx--;
            }
            
            if(idx > 0){
                jobAssigned[idx] = pair.first;
            }
        }
        
        int num_of_jobs = 0, maxProfit = 0;
        for(int i=1; i<maxDeadline+1; i++){
            if(jobAssigned[i] != -1){
                num_of_jobs++;
                maxProfit += jobAssigned[i];
            }
        }
        
        return {num_of_jobs, maxProfit};
    }
};
