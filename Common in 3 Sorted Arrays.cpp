// TC: O(n1+n2+n3) SC: O(n1 + n2 + n3)
class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {
        vector<int> result;
        unordered_map<int, int> numFreq;
        
        for(int& i: arr1) if(numFreq[i] == 0) numFreq[i] = 1;
        for(int& i: arr2) if(numFreq[i] == 1) numFreq[i] = 2;
        for(int& i: arr3) if(numFreq[i] == 2) numFreq[i] = 3;
        
        for(auto& p:numFreq) if(p.second == 3) result.push_back(p.first);
        
        sort(result.begin(), result.end());
        return result;
    }
};

// TC: O(n1+n2+n3) SC: O(1)
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
