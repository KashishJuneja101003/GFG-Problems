struct Item{
    int value;
    int weight;
    double ratio;
};

bool compare(Item* i1, Item* i2){
    return i1->ratio > i2->ratio;
}

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=wt.size();
        vector<Item*> items(n);
        
        // Making a structure for each item
        for(int i=0; i<n; i++){
            Item* newItem = new Item();
            newItem->value = val[i];
            newItem->weight = wt[i];
            newItem->ratio = (double)val[i]/wt[i];
            items[i] = newItem;
        }
        
        // Sort according to ratio
        sort(items.begin(), items.end(), compare);
        
        // Calculate Profit
        double maxProfit = 0.0;
        
        for(int i=0; i<n; i++){
            if(items[i]->weight <= capacity){
                maxProfit += items[i]->value;
                capacity -= items[i]->weight;
            } else{
                maxProfit += items[i]->ratio * capacity;
                break;
            }
        }
        
        return maxProfit;
    }
};
