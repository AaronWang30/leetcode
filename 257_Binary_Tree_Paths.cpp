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
    vector<string> r;
    void dfs(TreeNode* node, string str=""){
       if(!node->right&&!node->left) {
           r.push_back(str);
           return ;
       }
       if(node->left)
            dfs(node->left, str+"->"+to_string(node->left->val));
       if(node->right)
            dfs(node->right, str+"->"+to_string(node->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root)
            dfs(root,to_string(root->val));
        return r;
    }
};