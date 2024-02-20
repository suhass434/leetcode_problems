bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    // base case: when one tree ends other tree should end too
    if(p == NULL || q == NULL) return (p == q);
    
    // otherwise, the values should be equal at each node level.
    return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}
