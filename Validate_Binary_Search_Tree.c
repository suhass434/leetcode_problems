/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool help(struct TreeNode *root, long min, long max) {

    if (root == NULL)
        return true;

    if (root->val <= min || root->val >= max)
        return false;

    
    if (!help(root->left, min, root->val) || !help(root->right, root->val, max))
        return false;

    return true;
}

bool isValidBST(struct TreeNode* root) {

    if (root == NULL || (root->left == NULL && root->right == NULL))
        return true;

    return help(root, LONG_MIN, LONG_MAX);    
}
