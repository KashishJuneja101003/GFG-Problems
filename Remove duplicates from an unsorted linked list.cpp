// Brute Force TC: O(n^2) SC: O(1)
class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        if(!head || !head->next) return head;
        
        Node* curr = head;
        while(curr){
            Node* temp = curr;
            while(temp && temp->next){
                if(temp->next->data == curr->data){
                    Node* del = temp->next;
                    temp->next = temp->next->next;
                    delete del;
                    continue;
                }
                
                temp = temp->next;
            }
            
            curr = curr->next;
        }
        
        return head;
    }
};

// Using Boolean Vector TC: O(n) SC: O(1)
class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        if(!head || !head->next) return head;
        
        vector<bool> seen(1e6+1, false);
        
        Node* curr = head;
        
        while(curr){
            seen[curr->data] = true;
            if(curr->next && seen[curr->next->data]){
                Node* del = curr->next;
                curr->next = curr->next->next;
                delete del;
                continue;
            }
            curr = curr->next;
        }
        
        return head;
    }
};
