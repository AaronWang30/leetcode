/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Solution 1
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        TreeNode* prev(nullptr);
        TreeNode* temp = root;
        TreeNode* victim(nullptr);
        bool isFind(false);
        while(!isFind&&temp!=nullptr) {
            if(temp->val==key) {
                isFind = true;
                break;
            }
            prev = temp;
            temp = (key < temp->val) ? temp->left : temp->right; 
        }
        if(!isFind) {
            cout << "Not found" <<endl;
            return root;
        }
        if(!temp->left&&!temp->right) {
            if(temp==root) {
                delete temp;
                return nullptr;
            }
            if(prev->left==temp) prev->left = nullptr;
            else prev->right = nullptr;
            delete temp;
            return root;
        }
        if(!temp->left) {
          //  cout << "no left" <<endl;
            if(temp==root) {
                prev = temp->right;
                delete temp;
                return prev;
            }
            if(prev->left==temp) prev->left = temp->right;
            else prev->right = temp->right;
            delete temp;
            return root;
        }
        if(!temp->right) {
            if(temp==root) {
                prev = temp->left;
                delete temp;
                return prev;
            }
            if(prev->left==temp) prev->left = temp->left;
            else prev->right = temp->left;
            delete temp;
            return root;
        }
        victim = temp;
        prev = temp;
        temp = temp->right;
        if(temp->left == nullptr) {
            victim->val = temp->val;
            victim->right = temp->right;
            delete temp;
            return root;
        }
        while(temp->left!=nullptr) {
            prev = temp;
            temp = prev->left;
        }
        victim -> val = temp -> val;
        if(temp->right) prev->left = temp->right;
        else prev->left = nullptr;
        delete temp;
        return root;
    }
};
//Solution 2 from discuss, slower
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;    
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        else if (root->val < key)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left) {
                TreeNode* right = root->right;
                delete root;
                return right;
            }
            else if (!root->right) {
                TreeNode* left = root->left;
                delete root;
                return left;
            }
            else {
                TreeNode* successor = findMinNode(root->right); // find the inorder successor (the minimal node in right subtree)
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }
        return root;
    }
private:
    TreeNode* findMinNode(TreeNode* root) {
        if (root->left) return findMinNode(root->left);
        return root;
    }
};