/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Solution 1: pair 88.63%
class Solution {
private:
    pair<int, int> robHelper (TreeNode* root) {
        if (!root) {
            return make_pair(0, 0);
        }
        auto left = robHelper(root->left);
        auto right = robHelper(root->right);
        auto x = root->val + left.second + right.second; 
        auto y = max(left.first, left.second) + max(right.first, right.second);
        return make_pair(x, y);
    }
public:
    int rob(TreeNode* root) {
        auto result = robHelper(root);
        return max(result.first, result.second);
    }
}; 
//Solution 2: vector 60.70%
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> a = robhelper(root);
        return max(a[0],a[1]);
    }
    vector<int> robhelper(TreeNode* root) {
        if(root==nullptr) {
            return vector<int>(2,0);
        }
        vector<int> left = robhelper(root->left);
        vector<int> right = robhelper(root->right);
        vector<int> r(2);
        r[0] = max(left[0], left[1]) + max (right[0], right[1]);
        r[1] = root->val + left[0] + right[0];
        return r;
    }
};