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
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return depth(0,root);
    }
    int depth(int cur_depth, TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        if(root->left == nullptr && root->right == nullptr){
            return 1;
        }
        int left_depth = 1 + depth(cur_depth+1,root->left);
        int right_depth = 1 + depth(cur_depth+1,root->right);
        int max_depth = max(left_depth,right_depth);
        return max_depth;
    }
    
};
