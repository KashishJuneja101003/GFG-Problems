class Solution{
public:

    void create_tree(node* root0, vector<int> &vec){
        //Your code goes here
        queue<node*> q;
        q.push(root0);
        
        for(int i=1; i<7; i++){
            node* newNode = new node();
            newNode->data = vec[i];
            if(q.front()->left == nullptr){
                q.front()->left = newNode;
            } else if(q.front()->right == nullptr){
                q.front()->right = newNode;
                q.pop();
            }
            
            q.push(newNode);
        }
    }

};
