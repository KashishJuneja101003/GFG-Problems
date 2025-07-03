// TC: O(1) SC: O(1) (Fixed size array)
class twoStacks {
  public:
    vector<int> vec;
    int top1;
    int top2;
    
    twoStacks() {
        vec.resize(200, -1);
        top1 = -1;
        top2 = 200;
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        vec[++top1] = x;
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        vec[--top2] = x;
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        if(top1 == -1) return -1;
        else return vec[top1--];
    }

        
    // Function to remove an element from top of the stack2.
    int pop2() {
        if(top2 == 200) return -1;
        else return vec[top2++];
    }
};
