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
    void flatten(TreeNode* root) {
        while(root) {
            if(root->left&&root->right) {
                TreeNode* victim = root->left;
                while(victim->right) 
                    victim = victim->right;
                victim->right = root->right;
            }
            if(root->left) 
                root->right = root->left;
            root->left = nullptr;
            root = root->right;
        }   
    }
};