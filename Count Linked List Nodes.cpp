class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {

        // Code here
        Node* temp = head;
        int count = 0;
        while(temp != nullptr){
            count++;
            temp = temp->next;
        }
        
        return count;
    }
};
