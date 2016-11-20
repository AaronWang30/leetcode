/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//6ms, find depth first
class Solution {
public:
    int getHeight(TreeNode* root) {
        if(!root) return 0;
        return 1+ max(getHeight(root->left), getHeight(root->right));
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> r;
        vector<int> temp;
        if(!root) return r;
        int h;
        h = getHeight(root);
        r.resize(h);
        queue<TreeNode*> q;
        TreeNode* victim;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()) {
            victim = q.front();
            q.pop();
            if(victim==nullptr&&q.empty()) {
                r[--h]=temp;
                break;
            }
            if(victim==nullptr) {
                q.push(nullptr);
                r[--h]=temp;
                temp.clear();
            }
            else {
                if(victim->left) q.push(victim->left);
                if(victim->right) q.push(victim->right);
                temp.push_back(victim->val);
            }
        }
        // for(int i=0;i<r.size()/2;++i) {
        //     swap(r[i], r[r.size()-1-i]);
        // }
        return r;
    }
};
//9ms, no finding depth
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> r;
        vector<int> temp;
        if(!root) return r;
        queue<TreeNode*> q;
        TreeNode* victim;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()) {
            victim = q.front();
            q.pop();
            if(victim==nullptr&&q.empty()) {
                r.push_back(temp);
                break;
            }
            if(victim==nullptr) {
                q.push(nullptr);
                r.push_back(temp);
                temp.clear();
            }
            else {
                if(victim->left) q.push(victim->left);
                if(victim->right) q.push(victim->right);
                temp.push_back(victim->val);
            }
        }
        for(int i=0;i<r.size()/2;++i) {
            swap(r[i], r[r.size()-1-i]);
        }
        return r;
    }
};