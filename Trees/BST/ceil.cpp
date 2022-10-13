

// Function to return the ceil of given number in BST.
int findCeil(Node* root, int input) {

    int ceil = -1;  // hai toh woh root->data return kardo, nahi toh usse just bada wala return kardo
    while(root)
    {
        if(root->data == input){
            ceil = root->data;
            return ceil;
        }
        
        else if( input > root->data){
            root = root->right;
        }
        
        else{
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}