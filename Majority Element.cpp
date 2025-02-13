class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int candidate = arr[0], freq = 0, n=arr.size();
        
        for(int i:arr){
            if(freq == 0){
                candidate = i;
            }
            
            if(i == candidate){
                freq++;
            } else{
                freq--;
            }
            
        }
        
        
        // Calculating the frequency of a potential candidate
        int count = 0;
        for(int i:arr){
            if(i == candidate){
                count++;
            }
        }
        
        return (count > n/2) ? candidate : -1;
    }
};
