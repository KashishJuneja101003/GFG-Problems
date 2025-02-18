class Solution{
public:
    void insertAtBottom(stack<int> &St, int element){
        if(St.empty()){
            St.push(element);
            return;
        }
        
        int top = St.top();
        St.pop();
        insertAtBottom(St, element);
        St.push(top);
    }
    void Reverse(stack<int> &St){
        if(St.empty()){
            return;
        }
        
        int top = St.top();
        St.pop();
        Reverse(St);
        insertAtBottom(St, top);
    }
};
