class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        // code here
        StackNode* newNode = new StackNode(x);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        // code here
        if(top == nullptr){
            return -1;
        }
        
        int temp = top->data;
        top = top->next;
        return temp;
    }

    MyStack() { top = NULL; }
};
