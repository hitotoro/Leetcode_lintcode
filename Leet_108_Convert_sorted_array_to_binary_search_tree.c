/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* createNode(int start, int end, int* nums){
    int middle = 0;
    
    if(start > end)
        return NULL;
    
    middle = start + ((end-start+1)>>1);
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[middle];
    
    root->left = createNode(start, middle-1, nums);
    root->right = createNode(middle+1, end, nums);
    
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    
    if(numsSize == 0 || nums == NULL)
        return NULL;
    
    return createNode(0, numsSize-1, nums);
}