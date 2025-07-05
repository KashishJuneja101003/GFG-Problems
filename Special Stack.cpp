// Approach 1: stack of a pair TC: O(1) for each operation SC: O(n)
stack<pair<int, int>> minStack;

void push(stack<int>& s, int a) {
    s.push(a);
    
    int minEl = (minStack.empty()) ? a : min(a, minStack.top().second);
    
    minStack.push({a, minEl});
}

bool isFull(stack<int>& s, int n) {
    return s.size() == n;
}

bool isEmpty(stack<int>& s) {
    return s.size() == 0;
}

int pop(stack<int>& s) {
    int val = s.top();
    s.pop();
    minStack.pop();
    return val;
}

int getMin(stack<int>& s) {
    if(!minStack.empty()) return minStack.top().second;
    else return -1;
}

// Approach 2: Using two stacks TC: O(1) for each operation SC: O(n)
stack<int> minStack;

void push(stack<int>& s, int a) {
    s.push(a);
    
    if(minStack.empty() || a <= minStack.top()){
        minStack.push(a);
    }
    
}

bool isFull(stack<int>& s, int n) {
    return s.size() == n;
}

bool isEmpty(stack<int>& s) {
    return s.size() == 0;
}

int pop(stack<int>& s) {
    int val = s.top(); s.pop();
    
    if(minStack.top() == val) minStack.pop();
    
    return val;
}

int getMin(stack<int>& s) {
    return minStack.top();
}

// Approach 3: Constant Space TC: O(1) for each SC: O(1)
int minEl;
void push(stack<int>& s, int x) {
    if(s.empty()) {
        s.push(x);
        minEl = x;
    }
    else{
        if(x < minEl){
            int val = 2*x - minEl;
            s.push(val);
            minEl = x;
        } else {
            s.push(x);
        }
    }
}

bool isFull(stack<int>& s, int n) {
    return s.size() == n;
}

bool isEmpty(stack<int>& s) {
    return s.size() == 0;
}

int pop(stack<int>& s) {
    int top = s.top();
    s.pop();
    
    if(top < minEl){
        int actual = minEl;
        minEl = 2*minEl - top;
        return actual;
    } else {
        return top;
    }
}

int getMin(stack<int>& s) {
    return minEl;
}
