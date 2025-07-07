class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
    vector<int> result;
    if (!root) return result;

    queue<Node*> q;
    stack<int> st;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        st.push(curr->data); // Push current node's data

        // Push right first, so left is processed last (for reverse)
        if (curr->right) q.push(curr->right);
        if (curr->left) q.push(curr->left);
    }

    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }

    return result;
}};
