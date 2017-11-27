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
        // connectRecursively(root); // Recursive solution. Space O(n), Time O(n)
        
        // Solution: Space O(1), Time O(n)
        if(root == NULL)
            return ;
        
        TreeLinkNode *next = root;
        TreeLinkNode *cur = NULL;
        
        while(next->left) { // assuming completely balanced binary tree (traverse all levels)
            cur = next;
            while (cur) { // traverse all nodes in the level
                cur->left->next = cur->right; // every left child points to right child
                if (cur->next) // not last in tree level
                    cur->right->next = cur->next->left; // right child of cur, points to left child of next (in level) node
                cur = cur->next; // move to next node in level
            }
            next = next->left; // go to next level
        }
    }
    
    struct Node {
        TreeLinkNode *node;
        int level;
        Node(TreeLinkNode *n, int l) {
            node = n;
            level = l;
        }
    };
    
    void connectRecursively(TreeLinkNode *root) {
        if (root == NULL)
            return ;
        
        queue<Node*> q;
        Node *cur;
        cur = new Node(root, 0);
        
        while (true) {
            // add children
            if (cur->node->left != NULL) {
                Node *left;
                left = new Node(cur->node->left, cur->level+1);
                q.push(left);
            }
            if (cur->node->right != NULL) {
                Node *right;
                right = new Node(cur->node->right, cur->level+1);
                q.push(right);
            }

            // check last node
            if(q.empty()) {
                delete[] cur;
                break;
            }
            
            Node *nxt = q.front();
            q.pop();
            if(nxt->level == cur->level)
                cur->node->next = nxt->node;
            
            delete[] cur;
            cur = nxt;
        } 
    }
};
