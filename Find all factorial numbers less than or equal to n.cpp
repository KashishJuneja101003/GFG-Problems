class Solution {
  public:
    vector<long long> factorialNumbers(long long n) {
        long long int currFact = 1, i =2;
        vector<long long> vec;
        while(currFact <= n){
            vec.push_back(currFact);
            currFact *= i++;
        }
        
        return vec;
    }
};
