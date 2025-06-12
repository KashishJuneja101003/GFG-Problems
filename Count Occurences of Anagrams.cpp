// TC: O(n*k) SC: O(k) => O(1)
class Solution {
  public:
    bool isAnagram(unordered_map<char, int>& char_freq){
        for(auto& it:char_freq){
            if(it.second != 0) return false;
        }
        return true;
    }
    
    int search(string &pat, string &txt) {
        unordered_map<char, int> char_freq;
        for(char c:pat) char_freq[c]++;
        
        int i=0;
        int j=0;
        int countAnagrams = 0;
        
        while(j < txt.size()){
            char c = txt[j];
            char_freq[c]--;
            
            if(j-i+1 == pat.size()){
                if(isAnagram(char_freq)) countAnagrams++;
                char c = txt[i];
                char_freq[c]++;
                
                i++;
            }
            
            j++;
        }
        
        return countAnagrams;
    }
};
