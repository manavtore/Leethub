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
    int sumNumbers(TreeNode* root) {
        int totalsum = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        while(!q.empty()){
            auto [root,current] = q.front();
            q.pop();
            current = ( current * 10 ) + root->val;

            if(root->left==nullptr && root->right==nullptr) totalsum += current;

            if(root->left!=nullptr) q.push({root->left,current});
            if(root->right!=nullptr) q.push({root->right,current});

        }

        return totalsum;
        
    }
};