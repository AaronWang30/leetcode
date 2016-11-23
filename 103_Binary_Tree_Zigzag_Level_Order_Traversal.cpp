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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> r;
        if(!root) return r;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        TreeNode* temp;
        vector<int> level;
        bool dir=false;
        while(!q.empty()) {
            temp = q.front();
            q.pop();
            if(temp==nullptr) {
                if(dir)
                    reverse(level.begin(), level.end());
                r.push_back(level);
                level.clear();
                if(q.empty()) break;
                q.push(nullptr);
                dir = !dir;
            } else {
                level.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return r;
    }
};