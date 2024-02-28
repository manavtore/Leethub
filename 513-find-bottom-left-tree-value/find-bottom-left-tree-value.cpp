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
    int maxdepth;
    int bottomleftvalue;
    void dfs(TreeNode* node,int depth){
        if(node==nullptr) return;

        if(depth > maxdepth){
            maxdepth = depth;
            bottomleftvalue = node ->val;
        }
        dfs(node->left,depth+1);
        dfs(node->right,depth+1);
        
    }
    int findBottomLeftValue(TreeNode* root) {
        maxdepth = -1;
        bottomleftvalue = 0;
        dfs(root,0);
        return bottomleftvalue;
    }
};