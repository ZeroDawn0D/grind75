/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct value{
    bool isbal;
    int height;
    value(bool b, int h): isbal(b), height(h) {} 
};
typedef struct value value;

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        value ans = func(root);
        return ans.isbal;

    }

    value func(TreeNode* node){
        if(node==nullptr){
            value v(true,0);
            return v;
        }

        value vleft = func(node->left);
        value vright = func(node->right);
        bool isb = vleft.isbal && vright.isbal;
        bool ish = abs(vleft.height-vright.height) <= 1;
        bool cur_b = isb && ish;
        int cur_h = 1+ max(vleft.height,vright.height);
        value cur(cur_b, cur_h);
        return cur;
    }
};
