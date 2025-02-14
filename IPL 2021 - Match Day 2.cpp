class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        
        int left = 0, right = 0;
        vector<int> ans;
        deque<int> q;
        
        while(right < n){
            while(!q.empty() && q.back()<arr[right]){
                q.pop_back();
            }
            q.push_back(arr[right]);
            
            if(right-left+1 < k){
                right++;
            } else if(right-left+1 == k){
                ans.push_back(q.front());
                if(q.front() == arr[left]){
                    q.pop_front();
                }
                left++; right++;
                
            }
        }
        
        return ans;
    }
};
