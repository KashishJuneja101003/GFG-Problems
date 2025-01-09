class Solution {
    Node* head = nullptr, *tail = nullptr;
    
  public:
    void push_back(int data){
        Node* newNode = new Node(data);
        
        if(head == nullptr){
            head = tail = newNode;
            return;
        }
        
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        
    }
    
    Node* constructDLL(vector<int>& arr) {
        // code here
        for(int i:arr){
            push_back(i);
        }
        
        return head;
    }
};
