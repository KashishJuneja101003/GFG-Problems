/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    Node* mergeTwoSortedLists(Node* l1, Node* l2){
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        
        Node* result;
        if(l1->data <= l2->data){
            result = l1;
            result->bottom = mergeTwoSortedLists(l1->bottom, l2);
        } else{
            result = l2;
            result->bottom = mergeTwoSortedLists(l1, l2->bottom);
        }
        
        return result;
    }
    
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        if(root == nullptr) return nullptr;
        
        Node* head = flatten(root->next);
        
        return mergeTwoSortedLists(root, head);
    }
};
