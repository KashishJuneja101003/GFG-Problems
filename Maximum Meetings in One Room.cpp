class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        int n = S.size();
        
        vector<pair<int, pair<int, int>>> meets;  // {endTime, {startTime, index}}

        for (int i = 0; i < n; i++) {
            meets.push_back({F[i], {S[i], i + 1}});  // 1-based index
        }

        sort(meets.begin(), meets.end());  // Sort by end time

        int lastEndTime = -1;
        vector<int> meetNumber;

        for (auto& m : meets) {
            if (m.second.first > lastEndTime) {  // Check if start time > last end time
                meetNumber.push_back(m.second.second);  // Store meeting index
                lastEndTime = m.first;  // Update last end time
            }
        }
        
        sort(meetNumber.begin(), meetNumber.end());
        
        return meetNumber;
    }
};
