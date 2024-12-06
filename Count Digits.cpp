class Solution {
  public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        // code here
        int num = n, count = 0;
        
        while(num != 0){
            int remainder = num%10;
            num /= 10;
            if(remainder == 0) continue;
            
            if(n%remainder == 0) count++;
            
        }
        
        return count;
    }
};
