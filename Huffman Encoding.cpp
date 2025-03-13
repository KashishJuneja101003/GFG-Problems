struct node{
    int freq;
    char c;
    node* left;
    node* right;
    
    node(char c, int f) : c(c), freq(f), left(nullptr), right(nullptr){}
};

struct Compare{
    bool operator()(node* n1, node*n2){
        return n1->freq > n2->freq;
    }
};

void preOrder(node* root, string code, vector<string>& result){
    if(root == nullptr){
        return;
    }
    
    if(root->c != '$'){
        result.push_back(code);
    }
    
    preOrder(root->left, code+"0", result);
    preOrder(root->right, code+"1", result);
    
    return;
}

class Solution{
	public:
		vector<string> huffmanCodes(string S,vector<int> f,int N){
		    priority_queue<node* , vector<node*>, Compare> pq;
		    
		    // Pushing nodes in min heap 
		    for(int i=0; i<N; i++){
		        node* newNode = new node(S[i], f[i]);
		        pq.push(newNode);
		    }
		    
		    while(pq.size() > 1){
		      //  Extract node 1
		      node* left = pq.top(); pq.pop();
		      
		      //  Extract node 2
		      node* right = pq.top(); pq.pop();
		      
		      // Making a new node of addition of node 1 and 2
		      node* newNode = new node('$', left->freq + right->freq);  // '$' as dummy character
		      
		      newNode->left = left;
		      newNode->right = right;
		      
		      // Pushing new node to pq
		      pq.push(newNode);
		    }
		    
		    //  The last remaining node is the root of the Huffman Tree
		    node* root = pq.top();
		    
		    vector<string> result;
		    preOrder(root, "", result);
		    return result;
		}
};
