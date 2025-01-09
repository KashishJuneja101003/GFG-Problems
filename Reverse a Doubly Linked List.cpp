class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        DLLNode* curr= head, *prev = nullptr, *next=nullptr;
        
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            curr->prev = next;
            prev = curr;
            curr = next;
        }
        
        head = prev;
        
        return head;
    }
};
