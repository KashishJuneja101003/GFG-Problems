class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        // code here
        Node* newNode = new Node(data);
        
        Node* temp = head;
        
        for(int i=0; i<pos; i++){
            temp = temp->next;
        }
        
        if(temp->next != nullptr){
            newNode->next = temp->next;
            temp->next->prev = newNode;
        }
        
        newNode->prev = temp;
        temp->next = newNode;
        
        return head;
    }
};
