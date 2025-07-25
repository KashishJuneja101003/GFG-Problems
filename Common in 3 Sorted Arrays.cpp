class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {
        vector<int> result;
        
        int i = 0, j = 0, k = 0;
        int s1 = arr1.size(), s2 = arr2.size(), s3 = arr3.size();
        int last;
        
        while(i < s1 && j < s2 && k < s3){
            int a = arr1[i];
            int b = arr2[j];
            int c = arr3[k];
            int maxEl = max(a, max(b, c));
            
            if(a < maxEl) {i++; continue;}
            if(b < maxEl) {j++; continue;}
            if(c < maxEl) {k++; continue;}
            
            if(a != last){
                result.push_back(a);
                last = a;
            }
            
            i++; j++; k++;
        }
        
        
        return result;
    }
};
