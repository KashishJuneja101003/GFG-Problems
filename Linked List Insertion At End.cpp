class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        Node* newNode = new Node(x);
        
        if(head == nullptr){
            head = newNode;
            return head;
        }
        
        Node* temp = head;
        
        while(temp->next != nullptr){
            temp = temp->next;
        }
        
        temp->next = newNode;
        
        return head;
    }
};
