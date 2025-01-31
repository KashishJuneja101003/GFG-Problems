class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int i=0, j=0, n1=a.size(), n2=b.size(), x=0;
        
        while(i < n1 && j < n2){
            int el;
            if(a[i] <= b[j]){
                el = a[i]; i++;
            } else{
                el = b[j]; j++;
            }
            
            x++;
            
            if(x == k) return el;
        }
        
        while(i < n1){
            int el = a[i];
            i++; x++;
            if(x == k) return el;
        }
        
        while(j < n2){
            int el = b[j];
            j++; x++;
            if(x == k) return el;
        }
    }
};
