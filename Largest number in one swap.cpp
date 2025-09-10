// Brute Force TC: O(n^2) SC: O(1)
class Solution {
  public:
    string largestSwap(string &s) {
        int n = s.size();
        
        for(int i=0; i<n; i++){
            int idx = i;
            for(int j=i+1; j<n; j++){
                if(s[j] > s[idx]) idx = j;
            }
            
            if(idx != i) {
                swap(s[i], s[idx]); break;
            }
        }
        
        return s;
    }
};

// TC: O(n) SC: O(n)
class Solution {
  public:
    string largestSwap(string &s) {
        int n = s.size();
        vector<int> largest(n);
        
        largest[n-1] = n-1;
        
        for(int i=n-2; i>=0; i--){
            if(s[i] > s[largest[i+1]]) largest[i] = i;
            else largest[i] = largest[i+1];
        }
        
        
        for(int i=0; i<n; i++){
            if(s[i] < s[largest[i]]) {
                swap(s[i], s[largest[i]]);
                break;
            }
        }
        
        return s;
    }
};
