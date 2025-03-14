class Solution {
  public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        
        vector<pair<int, int>> meets;
        for (int i = 0; i < n; i++) {
            meets.push_back({end[i], start[i]});  // Sort by endTime
        }
        sort(meets.begin(), meets.end());
                
        int count = 0, lastEndTime = -1;
        for(auto& p:meets){
            if(p.second > lastEndTime){
                count++; lastEndTime = p.first;
            }
            
        }
        return count;
    }
};
