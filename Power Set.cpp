class Solution {
  public:
    void generateSets(string s, vector<string>& powerSet, string currSet, int idx){
        // Don't push empty set into power set
        if(idx >= s.size()){
            if(currSet != "") powerSet.push_back(currSet); 
            return;
        }
        
        currSet.push_back(s[idx]);
        generateSets(s, powerSet, currSet, idx+1);
        currSet.pop_back();
        generateSets(s, powerSet, currSet, idx+1);
    }
    
    vector<string> AllPossibleStrings(string s) {
        vector<string> powerSet;
        generateSets(s, powerSet, "", 0);
        sort(powerSet.begin(), powerSet.end());
        return powerSet;
    }
};
