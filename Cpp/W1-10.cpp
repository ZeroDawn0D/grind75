/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==nullptr){
            return nullptr;
        }
        if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left,p,q);
        }else if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p,q);
        }
        return root;

        
        
    }
};
//--------------------------------------------------------------------------------------------------------------
class Solution {
public:
    string find(TreeNode* root, TreeNode* node){
        string leftstr,rightstr;
        if(root==nullptr){
            return "0";
        }
        if(root==node){
            return "1";
        }
        if(root->left == nullptr && root->right ==nullptr){
            return "0";
        }
        //if(root->left != nullptr)
            leftstr = "L" + find(root->left,node);
        //if(root->left != nullptr)
            rightstr = "R" + find(root->right,node);
        if(leftstr[leftstr.size()-1]=='1'){
            return leftstr;
        }else{
            return rightstr;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        string p_loc = find(root,p);
        string q_loc = find(root,q);
        //cout<<p_loc<<endl;
        //cout<<p_loc[0]<<endl;
        //cout<<q_loc<<endl;
        TreeNode* ans = root;
        for(int i = 0; i < p_loc.size() && i < q_loc.size(); i++){
            if(p_loc[i]==q_loc[i]){
                //cout<<i<<endl;
                //cout<<p_loc[i]<<" "<<q_loc[i]<<"\n";
                if(p_loc[i]=='L'){
                    //cout<<"left\n";
                    ans = ans->left;
                }else if(p_loc[i]=='R'){
                    //cout<<"right\n";
                    ans = ans->right;
                }
            }else{
                break;
            }
        }
        //cout<<root->val;
        //cout<<ans->val;
        return ans;
    }
};
