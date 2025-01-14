class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        vector<pair<int, int>> vec;
        Node *left = head, *right = head;
        
        while(right->next != nullptr){
            right = right->next;
        }
        
        
        while(left != right && left->prev != right){
            if(left->data + right->data < target){
                left = left->next;
            } else if(left->data + right->data > target){
                right = right->prev;
            } else{
                vec.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
        }
        
        return vec;
    }
};
