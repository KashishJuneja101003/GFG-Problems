class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
    // If the list is empty or contains only one node, no need to reverse
    if (head == NULL || head->next == head) {
        return head;
    }
    
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    // This loop will reverse the links of the circular linked list
    do {
        next = current->next;  // Store next node
        current->next = prev;   // Reverse the link
        prev = current;         // Move prev to current
        current = next;         // Move current to next
    } while (current != head);  // Stop when we complete the full circle

    // At this point, current is at the head node
    // head should now point to the last node
    head->next = prev;
    head = prev;  // Update the head to be the new first node

    return head;
}


    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        // code here
        Node* temp = head;
        Node* prev;
        // Search for the element
        while(temp->next != head && temp->data != key){
            prev = temp;
            temp = temp->next;
        }
        
        // Element found
        if(temp->data == key){
            if(temp == head){
                Node* itr = head;
                while(itr->next != head){
                    itr = itr->next;
                }
                itr->next = head->next;
                head = itr->next;
            }
            else{
                prev->next = temp->next;
            }
            delete temp;
        }
        return head;        
    }
};
