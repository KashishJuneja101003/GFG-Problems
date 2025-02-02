class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        
        Node* temp = head, *ptr = head;
        int curr = head->data;
        
        while(temp != nullptr){
            if(temp->data == curr){
                temp = temp->next; continue;
            }
            
            curr = temp->data;
            temp->prev = ptr;
            ptr->next = temp;
            ptr = ptr->next;
        }
        
        ptr->next = nullptr;
        
        return head;
    }
};
