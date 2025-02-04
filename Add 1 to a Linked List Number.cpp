class Solution {
  public:
    Node* reverse(Node* head){
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head = prev;
        return head;
    }
    
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        if(head == nullptr){
            return nullptr;
        }
        
        head = reverse(head);
        
        // Add 1
        Node* temp = head, *prev;
        int carry = 1;
        
        while(temp != nullptr){
            int sum = temp->data + carry;
            
            temp->data = sum%10;
            carry = sum/10;
            
            prev = temp;
            temp = temp->next;
        }
        
        if(carry == 1){
            Node* newNode = new Node(1);
            prev->next = newNode;
            temp = prev->next;
        }
        
        head = reverse(head);
        
        return head;
    }
};
