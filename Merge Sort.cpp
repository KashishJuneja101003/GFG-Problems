class Solution {
  public:
    void merge(vector<int>& a, int l, int m, int r){
        vector<int> temp;
        int i=l, j=m+1;
        
        // Merge the two sorted halves
        while(i <= m && j <= r){
            if(a[i] <= a[j]) {
                temp.push_back(a[i]);
                i++;
            }
            else{
                temp.push_back(a[j]);
                j++;
            }
        }
        
        // Copy remaining elements
        while(i <= m){
            temp.push_back(a[i]);
            i++;
        }
        while(j <= r){
            temp.push_back(a[j]);
            j++;
        }
        
        // Copy the merged subarray into the original array
        for(int k=0; k<temp.size(); k++){
            a[l+k] = temp[k];
        }
    }
    
    void mergeSort(vector<int>& arr, int l, int r) {
        // If only 1 or no element, return 
        if(l >= r) return;
        
        int mid = l + (r-l)/2;
        
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
};
