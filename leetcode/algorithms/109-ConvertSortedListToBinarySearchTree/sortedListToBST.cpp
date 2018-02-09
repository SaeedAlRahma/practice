/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        // Check empty input
        if(head == NULL)
            return NULL;
        
        // Get list size
        ListNode *listNode = head;
        uint32_t size = 0;
        while(listNode != NULL) {
            size++;
            listNode = listNode->next;
        }
        
        // build a BST using in-order traversal on a sorted list
        listNode = head;
        return buildBST(&listNode, size);
    }
    
    /**
     * Recursive in-order traversal to convert sorted list to balanced BST
     * ListNode is global to all recursive calls (same address)
     * time: O(n), space: recursive
     */
    TreeNode* buildBST(ListNode** listNode, uint32_t size) {
        // create a place-holder tree node
        TreeNode *treeNode = new TreeNode(0);
        
        // base case leaf
        if(size == 1) {
            treeNode->val = (*listNode)->val;
            *listNode = (*listNode)->next;
            return treeNode;
        }
            
        
        /* In-order traversal */
        // recursively build left branch of tree
        // recursion will move list from first node to middle node
        treeNode->left = buildBST(listNode, size/2);
        
        // get current node
        // list is on middle node
        treeNode->val = (*listNode)->val;
        *listNode = (*listNode)->next;
        
        // recursively build right branch of tree
        // list is past middle node
        if(size>2) // 1st node left, 2nd node center, 3rd (or null) node right
            treeNode->right = buildBST(listNode, (size-1)/2); // size-1 to account for even-sized lists (have one less on the right)
        
        return treeNode;
    }
};
