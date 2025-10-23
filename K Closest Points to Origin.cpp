// TC: O(n log k) SC: O(k)
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        typedef pair<int, pair<int, int>> P;
        priority_queue<P> pq;
        
        for(vector<int>& point:points){
            int x = point[0];
            int y = point[1];
            int dist = x*x + y*y;
            pq.push({dist, {x, y}});
            
            if(pq.size() > k) pq.pop();
        }
        
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }

        return ans;
    }
};
