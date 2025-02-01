void MyStack ::push(int x) {
    // Your Code
    if(top == 1000){
        return;
    }
    
    arr[++top] = x;
}

// Function to remove an item from top of the stack.
int MyStack ::pop() {
    // Your Code
    if(top == -1){
        return -1;
    }
    
    return arr[top--];
}
