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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> r;
        if(!root) return r;
        bool flag=true;
        queue<TreeNode*> q;
        queue<TreeNode*> temp_q;
        temp_q.push(root);
        TreeNode* temp;
        while(flag) {
            flag=false;
            swap(q,temp_q);
            while(!q.empty()) {
                temp=q.front();
                q.pop();
                if(temp->left) {
                    temp_q.push(temp->left);
                    flag=true;
                }
                if(temp->right) {
                    temp_q.push(temp->right);
                    flag=true;
                }
            }
            r.push_back(temp->val);
           
        }
    return r;    
    }
};