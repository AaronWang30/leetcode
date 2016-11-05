/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//solution 1 stack
class BSTIterator {
public:
    vector<int> list;
    int p=0;
    BSTIterator(TreeNode *root) {
        stack<TreeNode*> s;
        while(root||!s.empty()) {
            while(root) {
                s.push(root);
                root = root->left;
                }
            if(!s.empty()) {
                root=s.top();
                s.pop();
                list.push_back(root->val);
                root = root->right;
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (p<list.size());
    }

    /** @return the next smallest number */
    int next() {
        return list[p++];
    }
};
//solution 2 recursion (a little faster)
class BSTIterator {
public:
    vector<int> list;
    int p=0;
    void TreeToList(TreeNode *root) {
        if(root->left) TreeToList(root->left);
        list.push_back(root->val);
        if(root->right) TreeToList(root->right);
    }
    BSTIterator(TreeNode *root) {
        if(root) TreeToList(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (p<list.size());
    }

    /** @return the next smallest number */
    int next() {
        return list[p++];
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */