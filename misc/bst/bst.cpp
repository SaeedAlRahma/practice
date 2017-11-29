#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

/** Definition for a binary tree node */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printInorder(TreeNode *root);
void printPreorder(TreeNode *root);
void printPostorder(TreeNode *root);
/** Print an indented tree strcture */
void printTree(TreeNode *root, string space);
/** Print Breadth First Search */
void printBFS(TreeNode *root);
/** Recover BST with one mistake (swapped nodes) */
void recoverTree(TreeNode* root);
/** Validate a given BST tree */
bool isValidBST(TreeNode* root);
/** Convert a sorted array to a BST */
TreeNode* sortedArrayToBST(vector<int>& nums);


/* Main Method */
int main() {
  /* TEST 1 - convert sorted array to BST */
  cout << "---------- TEST 1 ----------" << endl;
  vector<int> nums = {1,2,3,4,5,6,7,8};
  TreeNode *root = sortedArrayToBST(nums);
  // print BST
  cout << "In-Order: ";
  printInorder(root);
    cout << "" << endl;
  cout << "BFS: ";
  printBFS(root);
    cout << "" << endl;
  cout << "Indented Tree Structure: " << endl;
  printTree(root, "");
  cout << endl;
  
  /* TEST 2 - validate BST created above */
  cout << "---------- TEST 2 ----------" << endl;
  cout << "BST validity: " << isValidBST(root) << endl;
    cout << "" << endl;
  
  /* TEST 3 - creating a BST with one mistake and correct it */
  cout << "---------- TEST 3 ----------" << endl;
  vector<int> nums2 = {1,2,3,4,5,8,7,6}; // 8 and 6 swapped
  root = sortedArrayToBST(nums2);
  // print wrong BST
  cout << "In-Order: ";
  printInorder(root);
    cout << "" << endl;
  cout << "BFS: ";
  printBFS(root);
    cout << "" << endl;
  cout << "Indented Tree Structure: " << endl;
  printTree(root, "");
  // Confirm invalid BST
  cout << "BST validity: " << isValidBST(root) << endl;
  // Fix BST
  recoverTree(root);
  // print recovered BST
  cout << "In-Order: ";
  printInorder(root);
    cout << "" << endl;
  cout << "BFS: ";
  printBFS(root);
    cout << "" << endl;
  cout << "Indented Tree Structure: " << endl;
  printTree(root, "");
  // Confirm valid BST
  cout << "BST validity: " << isValidBST(root) << endl;

  
  return 0;
}

/** Helper method for recoverTree
 *  In order traversal of a BST must be in ascending order
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
      if (is_second_wrong) return true;
    }
  }
  
  prev = root; // update prev for right node
  return bstSwapFix(root->right, prev, wrong1, wrong2); // return right sub-tree swap
}

/** Recover BST with one mistake (swapped nodes) */
void recoverTree(TreeNode* root) {
  TreeNode *prev = NULL;
  TreeNode *wrong1 = NULL;
  TreeNode *wrong2 = NULL;
  bstSwapFix(root, prev, wrong1, wrong2);
  
  // Swap wrong nodes to corred tree
  int tmp = wrong1->val;
  wrong1->val = wrong2->val;
  wrong2->val = tmp;
}

/** Helper method for isValidBST */
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

/** Validate a given BST tree */
bool isValidBST(TreeNode* root) {
  // returns true if in order traversal is ascending
  TreeNode *prev = NULL;
  return bstValidInOrder(root, prev);
}

/** Helper method for sortedArrayToBST */
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

/** Convert a sorted array to a BST */
TreeNode* sortedArrayToBST(vector<int>& nums) {
  TreeNode *root = sortedArrayToBstRecursive(nums, 0, nums.size()-1);

  return root;
}

void printInorder(TreeNode *root) {
  if (root == NULL)
    return ;
  
  printInorder(root->left);
  cout << root->val << " ";
  printInorder(root->right);  
}

void printPreorder(TreeNode *root) {
  if (root == NULL)
    return ;
  
  cout << root->val << " ";
  printPreorder(root->left);
  printPreorder(root->right);
}

void printPostorder(TreeNode *root) {
  if (root == NULL)
    return ;
  
  printPostorder(root->left);
  printPostorder(root->right);
  cout << root->val << " ";
}

/** Print an indented tree strcture */
void printTree(TreeNode *root, string space) {
  if (root == NULL)
    return ;
  
  cout << space << root->val << " " << endl;
  printTree(root->left, space+"L--");
  printTree(root->right, space+"R--");
}

/** Print Breadth First Search */
void printBFS(TreeNode *root) {
  
  queue<TreeNode*> q;
  q.push(root);
  
  while (!q.empty()) {
    TreeNode *cur = q.front();
    q.pop();
    cout << cur->val << " ";
    
    if (cur->left)
      q.push(cur->left);
    
    if (cur->right)
      q.push(cur->right);
  }  
}
