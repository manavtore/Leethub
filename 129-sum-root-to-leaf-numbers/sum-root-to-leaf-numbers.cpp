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
    void cal(TreeNode* root,int current,int& sum){
        current =(current*10)+root->val;
        if(root->left==nullptr && root->right==nullptr){
            sum+=current;
        }
        
        if(root->left!=nullptr){
            cal(root->left,current,sum);
        }
        if(root->right!=nullptr){
            cal(root->right,current,sum);
        }
    }
    int sumNumbers(TreeNode* root) {
        int sum =0;
        if(root->left==nullptr && root->right==nullptr) return root->val;
        cal(root,0,sum);

        return sum;
    }
};