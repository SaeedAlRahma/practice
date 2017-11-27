/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // connectSlow(root);
        // return ;
        
        // Solution: Space O(1), Time O(n)
        TreeLinkNode *cur = root;
        TreeLinkNode *head = NULL;
        TreeLinkNode *prev = NULL;
        
        while (cur) { // Traverse all tree levels
            while (cur) { // Travrse all nodes in a level
                if (cur->left) { // left child exist
                    if(!prev) // first child (head)
                        head = cur->left;
                    else
                        prev->next = cur->left; // last level node points here
                    
                    prev = cur->left; // move previous node pointer
                }
                
                if (cur->right) { // right child exist
                    if(!prev) // first child (head)
                        head = cur->right;
                    else
                        prev->next = cur->right; // last level node points here
                    
                    prev = cur->right; // move previous node pointer
                }
                
                cur = cur->next; // Move to next node in the same level
            }
            
            cur = head; // Move to next level
            // Reset variables
            head = NULL;
            prev = NULL;
        }
    }
    
    /** Solution: Space O(1), Time O(n^2) */
    void connectSlow(TreeLinkNode *root) {
        if(root == NULL)
            return ;
        
        TreeLinkNode *node = root;
        TreeLinkNode *cur = NULL;
        
        while(node != NULL) { // traverse all levels
            cur = node;
            while (cur) { // traverse all nodes in the level
                if (cur->left)
                    if(cur->right) // left and right children exist
                        cur->left->next = cur->right; // left child points to tight child
                    else // left must point to the next available child of next nodes
                        cur->left->next = getNext(cur->next);
                if (cur->right) // right must point to the next available child of next nodes
                    cur->right->next = getNext(cur->next); 
                cur = cur->next; // move to next node in level
            }
            
            // move to next level
            while(node != NULL) {
                if (node->left) {
                    node = node->left;
                    break;
                }  
                else if (node->right) {
                    node = node->right;
                    break;
                }
                else
                    node = node->next;
            }            
        }
    }
    
    
    TreeLinkNode* getNext(TreeLinkNode *node) {       
        TreeLinkNode *cur = node;
        while(cur != NULL) {
            if (cur->left)
                return cur->left;
            else if (cur-> right)
                return cur->right;
            else
                cur = cur->next;
        }

        return NULL; // no next node found
    }
};
