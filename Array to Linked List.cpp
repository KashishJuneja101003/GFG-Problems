class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        // code here
        Node* head = new Node(arr[0]);
        Node* temp = head;
        
        for(int i=1; i<arr.size(); i++){
            Node* nnode = new Node(arr[i]);
            temp->next = nnode;
            temp = temp->next;
        }
        
        return head;
    }
};
