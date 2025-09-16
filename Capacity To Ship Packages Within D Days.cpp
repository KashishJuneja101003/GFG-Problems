class Solution {
  public:
    bool canShip(int arr[], int n, int days, int maxWt){
        int day = 1;
        int cap = 0;
        
        for(int i=0; i<n; i++){
            if(arr[i] > maxWt) return false;
            
            if(cap + arr[i] <= maxWt){
                cap += arr[i]; 
            } else{
                cap = arr[i];
                day++;
            }
            
            
            if(day > days) return false;
        }
        
        return day <= days;
    }
  
    int leastWeightCapacity(int arr[], int n, int d) {
        int left = 1;
        int right = 0;
        
        for(int i=0; i<n; i++) right += arr[i];
        
        int ans = 0;
        
        while(left <= right){
            int mid = left + (right-left)/2;
            
            if(canShip(arr, n, d, mid)){
                ans = mid;
                right = mid-1;
            } else{
                left = mid+1;
            }
        }
        
        return ans;
    }
};
