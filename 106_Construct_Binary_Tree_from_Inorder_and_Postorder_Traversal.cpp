//Solution 1 stack 96.85%
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int size(inorder.size());
        if(size == 0) return nullptr;
        TreeNode *temp;
        TreeNode *root;
        stack<TreeNode *> st;
        int i(size-1), j(size-1);
        root = new TreeNode(postorder[j--]); 
        st.push(root); 
        while(true) {
            if(inorder[i]!=st.top()->val) {
                TreeNode *node = new TreeNode(postorder[j--]);
                st.top()->right = node;
                st.push(node);
            } else {
                temp = st.top();
                st.pop();
                if(--i<0) break;
                if(!st.empty() && inorder[i]==st.top()->val)
                    continue;
                temp -> left = new TreeNode(postorder[j--]);
                st.push(temp->left);
                
            }
        }
      
        return root;
    }
};
//Solution 2 recursion 95.57%
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
    vector<int> inorder;
    vector<int> postorder;
    unordered_map<int, int> inMap;
public:
    TreeNode* buildTree(vector<int>& inorder1, vector<int>& postorder1) {
        inorder = move(inorder1);
        postorder = move(postorder1);
        int size = inorder.size();
        if(!size) return nullptr;
        int i(0);
        for(;i<size;++i) 
            inMap[inorder[i]] = i;
        int r = postorder[size-1];
        TreeNode* root = new TreeNode(r);
        i = inMap[r];
        root->left = build(0,i,0,i);//0<=x<i
        root->right = build(i+1,size,i,size-1);
        return root;
    }
    TreeNode* build(int in_first, int in_end, int post_first, int post_end) {

        if(in_end<=in_first) return nullptr;
        int r = postorder[post_end-1];
        TreeNode* root = new TreeNode(r);
        if(post_first==post_end-1) return root;
        else {
            int i = inMap[r];
            root->left = build(in_first, i, post_first, post_first+i-in_first);
            root->right = build(i+1, in_end, post_first+i-in_first, post_end-1);
            return root;
        }
    }
};