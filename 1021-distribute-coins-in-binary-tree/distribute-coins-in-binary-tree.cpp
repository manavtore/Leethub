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
    int dfs(TreeNode* root,int& moves){
        if(!root) return 0;

        int left = dfs(root->left,moves);
        int right = dfs(root->right,moves);
        
        int total = root->val-1 + left +right;
        moves += abs(left)+abs(right);
        return total;
    }
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        dfs(root,moves);
        return moves;
    }
};