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
private:
    vector<int> nums;
public:
    TreeNode* sortedArrayToBST(vector<int>& num) {
        if(num.size()==0) return nullptr;
        nums = num;
        TreeNode* root = new TreeNode(nums[nums.size()/2]);
        consLeft(root, 0, nums.size()/2-1);
        consRight(root, nums.size()/2+1, nums.size()-1);
        return root;
    }
    void consLeft(TreeNode* root, int l, int r) {
      //  cout << "consLeft with " << root->val << " with l and r " << l << " " << r <<endl;
        if(l>r) return ;
        if(l==r) {
            TreeNode* left = new TreeNode(nums[l]);
            root->left = left;
            return ;
        } else {
            TreeNode* left = new TreeNode(nums[(l+r)/2]);
            root -> left = left;
            consLeft(left, l, (l+r)/2 -1);
            consRight(left, (l+r)/2 + 1, r);
            return ;
        }
    } 
    void consRight(TreeNode* root, int l, int r) {
        //cout << "consRight with " << root->val << " with l and r " << l << " " << r <<endl;
        if(l>r) return ;
        if(l==r) {
            TreeNode* right = new TreeNode(nums[l]);
            root->right = right;
            return ;
        } else {
            TreeNode* right = new TreeNode(nums[(l+r)/2]);
            root -> right = right;
            consLeft(right, l, (l+r)/2 -1);
            consRight(right, (l+r)/2 + 1, r);
            return ;
        }
    } 
};