class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        Node* slow = head, *fast = head;
        bool isCycle = false;
        
        // Detect cycle
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                isCycle = true; break;
            }
        }
        
        if(!isCycle){   // Return 0 if cycle is not present
            return 0;
        }
        
        // starting node of cycle
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        // Count the nodes present in the cycle
        int count = 1;
        while(fast->next != slow){
            count++;
            fast = fast->next;
        }
        
        return count;
        
    }
};
