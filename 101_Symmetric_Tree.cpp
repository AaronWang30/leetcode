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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        stack<TreeNode*> lstack, rstack;
        TreeNode* ltemp = root->left;
        TreeNode* rtemp = root->right;
        lstack.push(ltemp);
        rstack.push(rtemp);
        while(!lstack.empty() && !rstack.empty()) {
            ltemp = lstack.top();
            rtemp = rstack.top();
            lstack.pop();
            rstack.pop();
            if(!ltemp && !rtemp) continue;
            if(!ltemp || !rtemp ||ltemp->val!=rtemp->val) return false;
            lstack.push(ltemp->right);
            lstack.push(ltemp->left);
            rstack.push(rtemp->left);
            rstack.push(rtemp->right);
        }
        return true;
    }
  
};