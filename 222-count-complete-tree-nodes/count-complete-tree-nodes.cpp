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
    void ans(TreeNode* root,int& n){
        if(root!=nullptr) n++;

        if(root->left!=nullptr) ans(root->left,n);
        if(root->right!=nullptr) ans(root->right,n);
    }
    int countNodes(TreeNode* root) {

        int n=0;
        if(root==nullptr) return n;
        ans(root,n);
        return n;
    }
};