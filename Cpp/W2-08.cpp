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
    int diameter = 0;
    int height(TreeNode* node){
        if(node==nullptr) return -1;
        if (node->left==nullptr && node->right==nullptr){
            return 0;
        }
        int left_height = height(node->left)+1;
        int right_height = height(node->right)+1;
        diameter = max(diameter, left_height+right_height);
        return max(left_height,right_height);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int temp = height(root);
        return diameter;
    }
};
