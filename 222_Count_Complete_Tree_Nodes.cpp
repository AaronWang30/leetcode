/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//98.59%!
class Solution {
public:
    bool flag=false;
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int h=0;
        TreeNode* temp=root;
        while(temp->left) {
            h++;
            temp=temp->left;
        }
        return count_helper(root, h);
    }
    int count_helper(TreeNode* root, int h) {
        if(!root) return 0;
        TreeNode* temp = root->left;
        int temp_h=0;
        while(temp) {
                temp=temp->right;
                temp_h++;
        }
        if(temp_h!=h) return (1<<temp_h) + count_helper(root->left,h-1);
        else return (1<<h) + count_helper(root->right,h-1);
           
    }
};