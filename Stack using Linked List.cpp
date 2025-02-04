class MyStack {
  private:
    StackNode *top;
    
    struct Node{
        int data;
        Node* next;
    };
    
    Node* head = nullptr;

  public:
    void push(int x) {
        // code here
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = head;
        head = newNode;
    }

    int pop() {
        // code here
        if(head == nullptr){
            return -1;
        }
        
        int temp = head->data;
        head = head->next;
        return temp;
    }

    MyStack() { top = NULL; }
};
