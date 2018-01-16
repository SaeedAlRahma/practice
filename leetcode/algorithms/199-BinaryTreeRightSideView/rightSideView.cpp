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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> seen;
        int max_level = -1;
                
        // add right side of the tree
        preOrderTraversal(root, &seen, &max_level, 0);
        
        return seen;
    }
    
private:
    // Modified preorder traversal
    // root, right, left
    // adds right-side view to int vector
    void preOrderTraversal(TreeNode *node, vector<int> *seen, int *max_level, int level) {
        // base case
        if(node == NULL)
            return;
        
        // root
        if(level > *max_level) {
            seen->push_back(node->val);
            *max_level = level;
        }
        
        // right
        preOrderTraversal(node->right, seen, max_level, level+1);
        
        // left
        preOrderTraversal(node->left, seen, max_level, level+1);
    }
};
