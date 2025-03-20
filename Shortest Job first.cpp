class Solution {
  public:
    long long solve(vector<int>& bt) {
        int n = bt.size();
        
        sort(bt.begin(), bt.end());
        
        long long waiting_time = 0;
        long long total_waiting_time = 0;
        
        for(int i=0; i<n-1; i++){
            waiting_time += bt[i];
            total_waiting_time += waiting_time;
        }
        
        
        long long avg_wt = total_waiting_time/n;
        
        return avg_wt;
    }
};
