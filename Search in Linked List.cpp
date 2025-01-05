class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, Node* head, int key) {
        // Code here
        for(Node* temp=head; temp!=nullptr; temp=temp->next){
            if(temp->data == key){
                return true;
            }
        }
        
        return false;
    }
};
