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
    TreeNode* sortedArrayToBstRecursive(vector<int>& nums, int lo, int hi) {
      if (hi < lo) // no more values left
        return NULL;
      else if (hi == lo) // last value
        return new TreeNode(nums[lo]);

      // more children
      int mid = (hi - lo + 1)/2; 
      TreeNode *node;
      node = new TreeNode(nums[lo+mid]);
      node->left = sortedArrayToBstRecursive(nums, lo, lo+mid-1);
      node->right = sortedArrayToBstRecursive(nums, lo+mid+1, hi);

      return node;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      TreeNode *root = sortedArrayToBstRecursive(nums, 0, nums.size()-1);

      return root;
    }
};
