int getTotalNodes(Node* root){
    if(root==NULL) return 0;
    return 1 + getTotalNodes(root->left) + getTotalNodes(root->right);
}

bool isHeap(Node* root, int rootIndex, int totalNodes, int bound){
    if(root==NULL) return true;
    if(root->data>bound) return false;
    if(rootIndex>=totalNodes) return false;
    return isHeap(root->left,2*rootIndex+1,totalNodes,root->data) 
    && isHeap(root->right,2*rootIndex+2,totalNodes,root->data);
}

bool isHeap(struct Node* tree) {
    int totalNodes = getTotalNodes(tree);
    return isHeap(tree,0,totalNodes,tree->data);
}
