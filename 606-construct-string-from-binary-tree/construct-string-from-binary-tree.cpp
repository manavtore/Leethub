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


    void solve(TreeNode* node,string &ans){
        if (node==nullptr) return;

        ans.append(to_string(node->val));
        if(node->left != nullptr || node->right != nullptr){
            ans.push_back('(');
            solve(node->left,ans);
            ans.push_back(')');
        }
        if(node->right != nullptr){
            ans.push_back('(');
            solve(node->right,ans);
            ans.push_back(')');
        }
    }
    string tree2str(TreeNode* root) {
        string ans="";
        solve(root,ans);
        return ans;
    }
};