// User function Template for C++


/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        
        Node*temp = *head_ref;
        
        while(temp != nullptr){
            if(temp->data == x){
                Node* delNode = temp;
                if(temp->prev != nullptr){
                    temp->prev->next = temp->next;
                } else{
                    *head_ref = temp->next;
                    temp->next->prev = nullptr;
                }
                if(temp->next != nullptr){
                    temp->next->prev = temp->prev;
                }
                
                temp = temp->next;
                
                delete delNode;
            } else{
                temp = temp->next;
            }
        }
    }
};
