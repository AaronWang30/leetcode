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
    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode*> q;
        if(root==nullptr) {
            return 0;
        }
        q.push(root);
        TreeNode* temp;
        int cnt=0;
        while(!q.empty()) {
            temp=q.front();
            q.pop();
            if(temp->left!=nullptr&&temp->left->left==nullptr&&temp->left->right==nullptr) cnt+=temp->left->val;
            else {
                if(temp->left!=nullptr) q.push(temp->left);
            }
            if(temp->right!=nullptr) q.push(temp->right);
        }
        return cnt;
    }
    
};
