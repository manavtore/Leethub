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
        if(root==nullptr) return nullptr;
        while(root!=nullptr){
            int curr = root->val;
            if(curr<q->val && curr<p->val){
                root=root->right;
             }else if(curr>q->val && curr>p->val ){
              root=root->left;
             }else{
                return root;
             }
        }
        
        
        return nullptr;
    }
};