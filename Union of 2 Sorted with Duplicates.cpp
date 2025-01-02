class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        
        int n1 = a.size(), n2 = b.size(), i = 0, j=0;
        set<int> mySet; int curr = INT_MIN;
        vector<int> result;
        
        while(i < n1 && j < n2){
            if (curr == a[i]){
                i++; continue;
            }
            if(curr == b[j]){
                j++; continue;
            }
            
            if(a[i] <= b[j]){
                curr = a[i];
                result.push_back(a[i]);
                i++;
            } else{
                curr = b[j];
                result.push_back(b[j]);
                j++;
            }
        }

        while(i < n1){
            if(curr == a[i]){
                i++; continue;
            }
            
            curr = a[i];            
            result.push_back(a[i]);i++;
        }
        
        while(j < n2){
            if(curr == b[j]){
                j++; continue;
            }
            curr = b[j];
            result.push_back(b[j]);j++;
        }
        return result;
    }
};
