/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Double stacks, beats 97.44%
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        if(preorder.size()==1) return root;
        stack<int> s;
        s.push(preorder[0]);
        stack<TreeNode*> sT;
        sT.push(root);
        int pos_pre(1);
        int pos_in(0);
        bool flag(false);
        TreeNode* temp = root;
        while(pos_pre<preorder.size()) {
            if(!sT.empty()&&sT.top()->val == inorder[pos_in]) {
                temp=sT.top();
                sT.pop();
                s.pop();
                ++pos_in;
                flag=true;
            } else {
                if(flag) {
                    flag=false;
                    s.push(preorder[pos_pre]);
                    temp->right = new TreeNode(preorder[pos_pre++]);
                    temp = temp->right;
                    sT.push(temp);
                } else {
                    s.push(preorder[pos_pre]);
                    temp->left = new TreeNode(preorder[pos_pre++]);
                    temp = temp->left;
                    sT.push(temp);
                }
            }

        }
        return root;
    }
};