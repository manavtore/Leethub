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
    void dfs(TreeNode* root, int parent, int depth,int x,int y,pair<int,int>& xInfo,pair<int,int>& yInfo){
        if(root==nullptr) return;

        if(root->val  == x){
            xInfo = {parent,depth};
        }

        if(root->val == y){
            yInfo = {parent,depth};
        }

        dfs(root->left,root->val,depth+1,x,y,xInfo,yInfo);
        dfs(root->right,root->val,depth+1,x,y,xInfo,yInfo);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int,int> xInfo(-1,-1);
        pair<int,int> yInfo(-1,-1);

        dfs(root,-1,0,x,y,xInfo,yInfo);

        return xInfo.second == yInfo.second && xInfo.first != yInfo.first;
    }
};