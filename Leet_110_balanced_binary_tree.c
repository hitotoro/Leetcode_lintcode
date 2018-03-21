/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int depth(struct TreeNode* root, int* isBalance){
    
    int diff = 0;
    
    if(root == NULL || *isBalance == 0)
        return 0;
    
    int depth_l = depth(root->left, isBalance) + 1;
    int depth_r = depth(root->right, isBalance) + 1;
    
    if(*isBalance){
        diff = (depth_l > depth_r) ? (depth_l - depth_r) : (depth_r - depth_l);
        *isBalance = (diff < 2) ? 1:0;
    }
    
    return (depth_l > depth_r) ? depth_l : depth_r;
    
}

bool isBalanced(struct TreeNode* root) {
    
    int isBalance = 1;
    depth(root, &isBalance);
    return isBalance;
    
}