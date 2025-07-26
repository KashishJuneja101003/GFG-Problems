// TC: O(n) SC: O(1)
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        int fives = 0;
        int tens = 0;
        int twenties = 0;

        for(int& amt:bills){
            if(amt == 5) fives++;
            else if(amt == 10){
                tens++;
                if(fives >= 1) fives--;
                else return false;
            }
            else if(amt == 20){
                twenties++;

                if(fives >=1 && tens >= 1) {
                    fives--; tens--;
                }
                else if(fives >= 3) {
                    fives -=3;
                }
                else{
                    return false;
                }
            }
        }

        return true;
    }
};
