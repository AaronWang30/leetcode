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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> r;
        if(!root) return r;
        vector<int> temp;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        TreeNode* node;
        while(!q.empty()) {
            node = q.front();
            q.pop();
            if(!node) {
                r.push_back(temp);
                temp.resize(0);
                if(q.empty()) break;
                q.push(nullptr);
            } else {
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                temp.push_back(node->val);
            }
        }
        return r;   
    }
};