/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:    
    int kthSmallest(TreeNode* root, int k) {
        int count = k;
        
        return inOrderTraversal(root, &count);
    
    int inOrderTraversal(TreeNode* node, int* count) {
        // base case
        if(node == NULL) return -1;
            
        // left
        int a = inOrderTraversal(node->left, count);
        if(a != -1) return a; // return answer if found kth smallest
        
        // current
        if(--(*count) == 0) return node->val; // return if this is kth smallest
        
        // right
        return inOrderTraversal(node->right, count); // find and return kth smallest
    }
};