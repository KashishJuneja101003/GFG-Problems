// Approach 1: TC: O(n*k) SC: O(k)
class Solution {
  public:
    vector<int> minPartition(int N) {
        vector<int> den = {1,2,5,10,20,50,100,200,500,2000};
        vector<int> result;
        
        for(int i=9; i>=0; i--){
            int numNotes = N / den[i];
            int rem = N % den[i];
            
            for(int k=0; k<numNotes; k++) result.push_back(den[i]);
            
            N = rem;
            if(N == 0) break;
        }
        return result;
    }
};

// Approach 1 (Clean Code): TC: O(n*k) SC: O(k)
class Solution {
  public:
    vector<int> minPartition(int N) {
        vector<int> den = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        vector<int> result;
        
        for(int i=0; i<10; i++){
            int val = den[i];
            while(N >= val){
                result.push_back(val);
                N -= val;
            }
        }
        return result;
    }
};
