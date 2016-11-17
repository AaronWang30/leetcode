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
        if(!root) return ;
        connectHelper(root);
    }
    void connectHelper(TreeLinkNode *root) {
        if(!root||(!root->left&&!root->right)) return ;
        TreeLinkNode *temp_left = root->left;
        TreeLinkNode *temp_right = root->right;
        while(temp_left&&temp_right) {
            temp_left->next=temp_right;
            temp_left = temp_left->right;
            temp_right = temp_right->left;
        }
        connectHelper(root->left);
        connectHelper(root->right);
    }
};