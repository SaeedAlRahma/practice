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
    // In order traversal of a BST must be in ascending order
    bool bstValidInOrder(TreeNode* root, TreeNode* &prev) {
      if(root == NULL)
        return true;

      // left node has no previous (inorder starts from left node)
      if (!bstValidInOrder(root->left, prev))
        return false; // left sub-tree is not valid

      // check myself (prev is updated by left child above)
      if(prev && (root->val <= prev->val))
        return false; // current sub-tree is not valid

      prev = root; // update prev for right node
      return bstValidInOrder(root->right, prev); // return right sub-treee validity
    }
    
public:
    bool isValidBST(TreeNode* root) {
      // returns true if in order traversal is ascending
      TreeNode *prev = NULL;
      return bstValidInOrder(root, prev);
    }
};
