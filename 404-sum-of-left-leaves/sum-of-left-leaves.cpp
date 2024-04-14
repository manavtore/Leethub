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
    void calculate(TreeNode* root,int& n,bool t){
        if(root->left==nullptr && root->right==nullptr && t==true){
            n = n + root->val;
        }

        if(root->left!=nullptr ){
               calculate(root->left,n,true);
        }

        if(root->right!=nullptr){
            calculate(root->right,n,false);
        } 

        return;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int n=0;
        calculate(root,n,false);
        return n;
    }
};