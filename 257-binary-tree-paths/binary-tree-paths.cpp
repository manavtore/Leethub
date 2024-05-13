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
    void inorder(TreeNode* root,string str,vector<string>& ans){
        if(root->left==nullptr && root->right==nullptr){
            ans.push_back(str+to_string(root->val));
        }
        string current = to_string(root->val)+"->";
        if(root->left!=nullptr){
            inorder(root->left,str+current,ans);
        }
        if(root->right!=nullptr){
            inorder(root->right,str+current,ans);
        }
        return ;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        inorder(root,"",ans);
        return ans;
    }
};