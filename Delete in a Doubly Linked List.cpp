class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        // Your code here
        if(x==1){
            head = head->next;
            head->prev = nullptr;
            
            return head;
        }
        
        Node* temp = head;
        Node*prev;
        for(int i=1; i<x; i++){
            prev = temp;
            temp = temp->next;
        }
        
        if(temp->next != nullptr){
            temp->next->prev = prev;
        }
        prev->next = temp->next;
        
        temp->prev = temp->next = nullptr;
        
        delete temp;
        
        return head;
    }
};
