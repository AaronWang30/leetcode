/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//59.21%
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> r;
        if(!root) return r;
        vector<TreeNode*> s;
        s.push_back(root);
        TreeNode* temp;
        TreeNode* prev=root;
        int temp_sum(root->val);
        
        while(!s.empty()) {
           temp=s.back();
           if(temp_sum==sum&&(!temp->left)&&(!temp->right)) {
               vector<int> to_push;
               for(auto &i:s) 
                    to_push.push_back(i->val);
               r.push_back(to_push);
           }
           if((!(temp->left)&&!(temp->right))||(temp->right==prev)||(temp->left==prev&&!temp->right)) {
               prev=temp;
               temp_sum-=temp->val;
               s.pop_back();
           } else {
               if((temp->right&&temp->left==prev)||!temp->left) {
                   s.push_back(temp->right);
                   prev=temp;
                   temp_sum+=temp->right->val;
               } 
               else if(temp->left) {
                        s.push_back(temp->left);
                        prev=temp;
                        temp_sum+=temp->left->val;
                   }
           }
        }
        return r;
    }
};