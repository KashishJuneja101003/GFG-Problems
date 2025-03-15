class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies, candies+N);
        
        // Min Amount
        int buy = 0, free = N-1, mini = 0;
        while(buy <= free){
            mini += candies[buy];
            buy++;
            free -= K;
        }
        
        int maxi = 0;
        buy = N-1; free = 0;
        while(buy >= free){
            maxi += candies[buy];
            buy--;
            free += K;
        }
        
        return {mini, maxi};
    }
};
