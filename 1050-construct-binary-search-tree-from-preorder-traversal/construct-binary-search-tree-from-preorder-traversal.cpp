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
    TreeNode* bstFromPreorder(vector<int>& V) {
        int i=0;
        return build(V,i,INT_MAX);
    }
    TreeNode* build(vector<int>& V,int& i,int Bound){
        if(i==V.size() || V[i]>Bound){
            return nullptr;
        }
        TreeNode* root = new TreeNode(V[i++]);
        root->left = build(V,i,root->val);
        root->right = build(V,i,Bound);
        return root;
    }
};