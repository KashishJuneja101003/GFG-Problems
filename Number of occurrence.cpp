class Solution {
  public:
  int findIndex(vector<int>& arr, int target, int start, int end){
      while(start <= end){
          int mid = start+(end-start)/2;
          
          if(arr[mid] == target) return mid;
          else if(arr[mid] > target) end = mid-1;
          else start = mid+1;
      }
      
      return -1;
  }
    int countFreq(vector<int>& arr, int target) {
        // code here
        int i=-1, j=-1, n=arr.size(), st=0, end=n-1;
        
        // Find least index
        while(i != 0){
            int temp = findIndex(arr, target, st, end);
            if(temp != -1){
                i = temp;
                end = i-1;
            } else{
                break;
            }
        }
        
        // Find Highest index
        st = 0, end = n-1;
        while(j != n-1){
            int temp = findIndex(arr, target, st, end);
            if(temp != -1){
                j = temp;
                st = j+1;
            } else{
                break;
            }
        }
        
        // cout<<"(i,j): "<<i<<" "<<j<<"\n";
        
        // If element doesn't exists, return 0
        if(i==-1 && j==-1) return 0;
        return (j-i+1);
    }
};
