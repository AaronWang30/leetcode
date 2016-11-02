/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream r;
        if(root==nullptr) {
            return r.str();
        }
        stack<TreeNode*> stk;
        TreeNode* temp;
        stk.push(root);
        while(!stk.empty()) {
            temp=stk.top();
            stk.pop();
            r << temp->val << "/";
            if(temp->right) stk.push(temp->right);
            if(temp->left) stk.push(temp->left);
        }
        return r.str();
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return nullptr;
        int place = 0, dis = 0;
        while(isdigit(data[dis])) dis++;
        TreeNode* root = new TreeNode(stoi(data.substr(place, dis)));
        TreeNode* temp = nullptr;
        TreeNode* cur = nullptr;
        place+=dis+1;
        stack<TreeNode*> s;
        s.push(root);
        while(place<data.size()) {
            cur=nullptr;
            dis=place;
            while(isdigit(data[dis]) && dis < data.size()) dis++;
            TreeNode* node = new TreeNode(stoi(data.substr(place, dis)));
            place = dis + 1;
            while(!s.empty() && (node->val) > (s.top() -> val)) {
                cur=s.top();
                s.pop();
            }
            if(cur) cur->right = node;
            else s.top()->left = node;
            s.push(node);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
