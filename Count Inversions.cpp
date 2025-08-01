// TC: O(n^2) SC: O(1)
class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        int count = 0;
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(arr[i] > arr[j]) count++;
            }
        }
        
        return count;
    }
};

// Merge Sort TC: O(n log n) SC: O(n)
class Solution {
  public:
    int merge(vector<int> &arr, int start, int mid, int end){
        int i = start;
        int j = mid+1;
        
        int invCount = 0;
        
        vector<int> temp;
        while(i <= mid && j <= end){
            if(arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            }
            else{
                invCount += (mid-i+1);
                temp.push_back(arr[j]);
                j++;
            }
        }
        
        while(i <= mid){
            temp.push_back(arr[i]);
            i++;
        }
        
        while(j <= end){
            temp.push_back(arr[j]);
            j++;
        }
        
        int idx = start;
        for(int i:temp) arr[idx++] = i;
        
        return invCount;
    }
    
    int mergeSort(vector<int> &arr, int start, int end){
        if(start >= end) return 0;
        
        int mid = start + (end-start)/2;
        int count = 0;
        
        count += mergeSort(arr, start, mid);
        count += mergeSort(arr, mid+1, end);
        count += merge(arr, start, mid, end);
        
        return count;
    }
    
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        
        return mergeSort(arr, 0, n-1);
    }
};
