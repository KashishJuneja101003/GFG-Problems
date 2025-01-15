class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        // If only 1 node is present
        if(head->next == nullptr){
            return head;
        }
        
        Node *Head0 = head, *Head1 = head, *Head2 = head;
        
        // Place head012 at right positions
        while(Head0 != nullptr && Head0->data != 0){
            Head0 = Head0->next;
        }
        while(Head1 != nullptr && Head1->data != 1){
            Head1 = Head1->next;
        }
        while(Head2 != nullptr && Head2->data != 2){
            Head2 = Head2->next;
        }
        
        Node *node0 = Head0, *node1 = Head1, *node2 = Head2, *temp = head;
        
        while(temp != nullptr){
            if(temp != Head0 && temp->data == 0){
                node0->next = temp;
                node0 = temp;
            } else if(temp != Head1 && temp->data == 1){
                node1->next = temp;
                node1 = temp;
            } else if (temp != Head2 && temp->data == 2){
                node2->next = temp;
                node2 = temp;
            }
            temp = temp->next;
            
        }
        
        // Linking
        if(Head0 != nullptr){
            if(Head1 != nullptr){
                node0->next = Head1;
            } else{
                node0->next = Head2;
            }
        }
        
        if(Head1 != nullptr){
            node1->next = Head2;
        }
        
        if(Head2 != nullptr){
            node2->next = nullptr;
        }
        
        
        // Returning Head
        if(Head0 != nullptr){
            return Head0;
        } else if(Head1 != nullptr){
            return Head1;
        } else{
            return Head2;
        }
    }
};
