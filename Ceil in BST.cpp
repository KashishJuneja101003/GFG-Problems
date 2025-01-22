int findCeil(Node* root, int X) {
    int ceilx = -1; // Initialize ceil to -1 (if no ceil is found)
    
    while (root) {
        if (root->data == X) {
            return root->data; // If the value matches X, it is the ceil
        }
        
        if (root->data < X) {
            // Move to the right subtree if the value is smaller than X
            root = root->right;
        } else {
            // Update ceil and move to the left subtree if the value is greater than X
            ceilx = root->data;
            root = root->left;
        }
    }
    
    return ceilx; // Return the found ceil or -1 if no ceil exists
}
