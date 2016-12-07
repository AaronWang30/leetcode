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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        TreeNode* temp;
        bool flag;
        if(root->left) {
            temp = root->left;
            flag = isValidBST(temp);
            while(temp->right)
                temp = temp->right;
            if(temp->val>=root->val||!flag) return false;
        }
        if(root->right) {
            temp = root->right;
            flag = isValidBST(temp);
            while(temp->left)
                temp = temp->left;
            if(temp->val<=root->val||!flag) return false;
        }
        return true;
    }
};