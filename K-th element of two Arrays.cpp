class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int i=0;
        int j=0;
        int n1=a.size();
        int n2=b.size();
        
        int ans;
        int idx = 0;
        
        while(i < n1 && j < n2){
            if(a[i] < b[j]){
                ans = a[i];
                i++;
            } else {
                ans = b[j];
                j++;
            }
            
            if(idx+1 == k) return ans;
            idx++;
        }
        
        while(i < n1 && idx != k){
            ans = a[i];
            i++;
            idx++;
        }
        
        while(j < n2 && idx != k){
            ans = b[j];
            j++;
            idx++;
        }
        
        return ans;
    }
};
