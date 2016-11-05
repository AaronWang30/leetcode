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
    int kthSmallest(TreeNode* root, int k) {
        int cnt = count(root->left)+1;
        if(cnt>k) {
            return kthSmallest(root->left,k);
        } else {
            if(cnt<k) {
                return kthSmallest(root->right,k-cnt);
            }
            else return root->val;
        }
    }
    int count(TreeNode* node) {
        if(!node) return 0;
        else return 1 + count(node->left) + count(node->right);
    }
};