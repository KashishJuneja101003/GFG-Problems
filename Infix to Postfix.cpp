class Solution {
  public:
    int getPriority(char op){
        if(op == '+' || op == '-') return 1;
        if(op == '*' || op == '/') return 2;
        if(op == '^') return 3;
        
        return 0;
    }
    
    string infixToPostfix(string& s) {
        stack<char> stk;
        string postfix = "";
        
        for(char c:s){
            if(isalpha(c) || isdigit(c)) postfix += c;
            else if(c == '(') stk.push(c);
            else if (c == ')'){
                while(stk.top() != '('){
                    postfix += stk.top();
                    stk.pop();
                }
                stk.pop();
            }
            else{
                int p = getPriority(c);
                while(!stk.empty() && getPriority(stk.top()) >= p){
                    postfix += stk.top();
                    stk.pop();
                }
                
                stk.push(c);
            }
        }
        
        while(!stk.empty()){
            postfix += stk.top();
            stk.pop();
        }
        
        return postfix;
    }
};
