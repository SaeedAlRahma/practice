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
    /** In order traversal of a BST must be in ascending order
     *  find the "one and only" mistake (two nodes)
      @param root tree current node
      @param prev tree previous node (in-order traversal)
      @param wrong1 first wrong node
      @param wrong2 second wrong node
      @return true to end traversal if both nodes found (optimization)
    */
    bool bstSwapFix(TreeNode* root, TreeNode* &prev, TreeNode* &wrong1, TreeNode* &wrong2) {
      if(root == NULL)
        return false;

      // left node has no previous (inorder starts from left node)
      if (bstSwapFix(root->left, prev, wrong1, wrong2))
        return true; // end search if swap complete

      // check myself (prev is updated by left child above)
      if(prev && (root->val <= prev->val)) {
        bool is_second_wrong = true;
        if (!wrong1) { // first wrong node
          wrong1 = prev; // first node will always be small (so prev)
          is_second_wrong = false;
        }
        if(wrong1) { // second wrong node --> swap
          wrong2 = root; // second node will always be bigger (so root)
          if (is_second_wrong) return true; // return true to end traversal (optimization)
        }
      }

      prev = root; // update prev for right node
      return bstSwapFix(root->right, prev, wrong1, wrong2); // return right sub-tree swap
    }
    
public:
    void recoverTree(TreeNode* root) {
        TreeNode *prev = NULL;
        TreeNode *wrong1 = NULL;
        TreeNode *wrong2 = NULL;
        bstSwapFix(root, prev, wrong1, wrong2);

        // Swap wrong nodes to correct tree
        int tmp = wrong1->val;
        wrong1->val = wrong2->val;
        wrong2->val = tmp;
    }
};
