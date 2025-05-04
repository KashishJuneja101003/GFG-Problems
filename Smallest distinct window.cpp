class Solution {
  public:
    int findSubString(string& str) {
        unordered_set<char> distinctElements;
        for(char c:str){
            distinctElements.insert(c);
        }
        
        int k = distinctElements.size();
        
        int left = 0;
        int right = 0;
        int n = str.size();
        unordered_map<char, int> char_freq;
        
        int windowSize = INT_MAX;
        while(right < n){
            char_freq[str[right]]++;
            
            if(char_freq.size() >= k) {
                // Reduce window size
                while(char_freq[str[left]] > 1){
                    char_freq[str[left]]--; left++;
                }
                windowSize = min(windowSize, right-left+1);
            }
            
            right++;
        }
        
        return windowSize;
        
    }
};
