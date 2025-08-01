/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
#include <stack>

class Solution {
  public:
    Node* addTwoLists(Node* head1, Node* head2) {
        stack<int> stk1, stk2;
        
        Node* temp = head1;
        
        while(temp){
            stk1.push(temp->data);
            temp = temp->next;
        }
        
        temp = head2;
        
        while(temp){
            stk2.push(temp->data);
            temp = temp->next;
        }
        
        int carry = 0;
        
        Node* Head = nullptr;
        
        while(!stk1.empty() || !stk2.empty()){
            int n1 = 0;
            if(!stk1.empty()){
                n1 = stk1.top(); stk1.pop();
            }
            
            int n2 = 0;
            if(!stk2.empty()){
                n2 = stk2.top(); stk2.pop();
            }
            
            int sum = n1+n2+carry;
            carry = sum/10;
            
            Node* newNode = new Node(sum%10);
            newNode->next = Head;
            Head = newNode;
        }
        
        if(carry == 1){
            Node* newNode = new Node(1);
            newNode->next = Head;
            Head = newNode;
        }

        
        // Remove leading zeroes
        while(Head && Head->data == 0) Head = Head->next;
        
        return Head;
    }
};
