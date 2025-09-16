class Solution {
  public:
    bool canPlace(int cows, vector<int> &stalls, int minDist){
        int count = 1;
        int lastPos = stalls[0];
        
        for(int stall:stalls){
            if(stall-lastPos >= minDist){
                lastPos = stall;
                count++;
                if(count >= cows) return true;
            }
        }
        
        return false;
    }
  
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        
        int left = 1;
        int right = stalls[stalls.size()-1] - stalls[0];
        
        int ans = 0;
    
        while(left <= right){
            int mid = left + (right-left)/2;
            
            if(canPlace(k, stalls, mid)){
                ans = mid;
                left = mid+1;
            } else{
                right = mid-1;
            }
        }
        
        return ans;
    }
};
