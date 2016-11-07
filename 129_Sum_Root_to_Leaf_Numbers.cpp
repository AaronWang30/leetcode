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
    int result=0;
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        findLeaf(root,0);        
        return result;
    }
    void findLeaf(TreeNode* node, int step) {
        step=step*10+node->val;
        if(!node->left&&!node->right) {
            result+=step;
            return ;
        }
        if(node->left) findLeaf(node->left, step);
        if(node->right) findLeaf(node->right,step);
    }
};