class Solution {
  public:
    int calcHours(vector<int>& arr, int bph){
        int hours = 0;
        for(int& i:arr){
            hours += ceil(1.0*i/bph);
        }
        
        return hours;
    }
    
    int kokoEat(vector<int>& arr, int k) {
        int left = 1;
        int right = *max_element(arr.begin(), arr.end());
        int ans = 0;
        
        while(left <= right){
            int mid = left + (right-left)/2;
            
            int hoursTaken = calcHours(arr, mid);
            
            if(hoursTaken > k) left = mid+1;
            else {
                ans = mid;
                right = mid-1;
            }
        }
        
        return ans;
    }
};
