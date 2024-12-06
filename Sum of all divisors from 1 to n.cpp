class Solution {
  public:
    int sumOfDivisors(int n) {
        // Write Your Code here
        int sum = 1;
        for(int i=2; i<=n; i++){
            sum++;
            for(int j=2; j <= i; j++){
                if(i%j == 0) sum += j;
            }
            
            // cout<<"SUM: "<<sum<<"\n";
        }
        
        return sum;
    }
};
