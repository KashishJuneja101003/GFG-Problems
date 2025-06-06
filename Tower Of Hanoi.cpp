class Solution {
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        int count = 0;
        
        // n-1 nodes : From -> Aux
        count += towerOfHanoi(n-1, from, aux, to);
        
        // nth node : From -> To by Recursive call
        // count += towerOfHanoi(1, from, to, aux);
        
        // nth node : From -> To in O(1)
        count++;
        
        
        // n-1 nodes : Aux -> To
        count += towerOfHanoi(n-1, aux, to, from);
        
        return count;
    }
};
