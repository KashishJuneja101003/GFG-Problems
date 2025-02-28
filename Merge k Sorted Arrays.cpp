class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> mergeSortedArray;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto i:arr){
            for(int j:i){
                pq.push(j);
            }
        }
        
        while(!pq.empty()){
            mergeSortedArray.push_back(pq.top());
            pq.pop();
        }
        
        return mergeSortedArray;
    }
};
