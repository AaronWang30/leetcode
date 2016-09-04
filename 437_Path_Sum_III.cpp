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
    struct Node {
        TreeNode* node;
        int v;
    };
    int pathSum(TreeNode* root, int sum) {
        queue<Node> q;
        if(root==nullptr) return 0;
        pushb(root, q);
        Node temp, b;
        int cnt=0;
        while(!q.empty()) {
            temp=q.front();
            q.pop();
            if(temp.node->val+temp.v==sum) cnt++;
            if(temp.node->left!=nullptr) {
                b={temp.node->left, temp.v+temp.node->val};
                q.push(b);
            }
            if(temp.node->right!=nullptr) {
                b={temp.node->right, temp.v+temp.node->val};
                q.push(b);
            }
        }
        return cnt;
    }
    void pushb(TreeNode*a, queue<Node> &b) {
        Node t= {a, 0};
        b.push(t);
        if(a->left!=nullptr) pushb(a->left,b);
        if(a->right!=nullptr) pushb(a->right,b);
    }
};
//Solution 2 unordered_map
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> m;
        m[0]++;
        
        int total = 0;
        helper(root, 0, sum, total, m);
        return total;
    }
    
    void helper(TreeNode *p, int cur, int sum, int &total, unordered_map<int, int> &m) {
        if (!p) return;
        
        cur += p->val;
        cout << "current: "<<cur <<endl;
        if (m.find(cur - sum) != m.end()) total += m[cur - sum];
        cout << "Total: "<<total <<endl;
        m[cur]++;
        
        helper(p->left, cur, sum, total, m);
        helper(p->right, cur, sum, total, m);
        
        m[cur]--;
    }
};
