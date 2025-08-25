class Solution {
  public:
    bool isSubset(vector<int> &a, vector<int> &b) {
        unordered_map<int, int> mp;
        
        for(int& i:a) mp[i]++;
        
        for(int& i:b){
            if(mp.find(i) == mp.end()) return false;
            mp[i]--;
            if(mp[i] == 0) mp.erase(i);
        }
        
        return true;
    }
};
