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
    vector<vector<int>> ans;
    void func(TreeNode* node, int pos){
        if(node==nullptr){
            return;
        }
        if(ans.size()<=pos){
            ans.resize(pos+1);
            cout<<"resized: "<<pos+1<<"\n";
        }
        ans[pos].push_back(node->val);
        func(node->left,pos+1);
        func(node->right,pos+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        func(root,0);
        return ans;
    }
    
};
