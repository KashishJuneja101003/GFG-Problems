class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        vector<pair<int, int>> time;
        int n = start.size();
        for(int i=0; i<n; i++){
            time.push_back({finish[i], start[i]});
        }
        
        sort(time.begin(), time.end());
        
        int count = 0;
        int finTime = 0;
        
        for(auto& p  : time){
            int end = p.first;
            int start = p.second;
            
            if(start > finTime){
                finTime = end;
                count++;
            }
        }
        
        return count;
    }
};
