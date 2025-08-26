//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size();
        int count = 0;
        int el1 = -1;
        int el2 = -1;
        int i=0;
        int j=0;
        
        while(i < n && j < n){
            int ans;
            
            if(arr1[i] <= arr2[j]){
                ans = arr1[i]; i++;
            } else {
                ans = arr2[j]; j++;
            }
            
            if(count == n-1) el1 = ans;
            if(count == n) {
                el2 = ans; break;
            }
            
            count++;
        }
        
        while(i < n && el2 == -1){
            int ans = arr1[i]; i++;
            
            if(count == n-1) el1 = ans;
            if(count == n) {
                el2 = ans; break;
            }
            
            count++;
        }
        
        while(j < n && el2 == -1){
            int ans = arr2[j]; j++;
            
            if(count == n-1) el1 = ans;
            if(count == n) {
                el2 = ans; break;
            }
            
            count++;
        }
        
        return el1 + el2;
    }
};
