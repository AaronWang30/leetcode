/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//solution 1 stack
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> r;
        if(!root) return r;
        stack<TreeNode* > s;
        s.push(root);
        TreeNode* temp;
        while(!s.empty()) {
            temp=s.top();
            s.pop();
            r.push_back(temp->val);
            if(temp->right) s.push(temp->right);
            if(temp->left) s.push(temp->left);
        }
        return r;
    }
};
//solution 2 recursion
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> r;
        if(!root) return r;
        traversal(root, r);
        return r;
    }
    void traversal(TreeNode* root, vector<int> &r) {
        if(!root) return ;
        r.push_back(root->val);
        traversal(root->left, r);
        traversal(root->right, r);
    }
    
};