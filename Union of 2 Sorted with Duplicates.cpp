class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        
        int n1 = a.size(), n2 = b.size(), i = 0, j=0;
        set<int> mySet;
        
        while(i < n1 && j < n2){
            if(a[i] <= b[j]){
                mySet.insert(a[i]); i++;
            } else{
                mySet.insert(b[j]); j++;
            }
        }

        while(i < n1){
            mySet.insert(a[i]); i++;
        }
        
        while(j < n2){
            mySet.insert(b[j]); j++;
        }
        
        
        
        vector<int> result;
        for(int i:mySet){
            result.push_back(i);
        }
        
        return result;
    }
};
