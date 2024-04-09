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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        queue<TreeNode*> q;
        int flag=0;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> level(size);
            for(int i=0;i<size;i++){
                TreeNode* current = q.front();
                q.pop();
                int index = (flag==0) ? i : size-i-1;
                level[index]= current->val;
                   if(current->left!=nullptr) q.push(current->left);
                   if(current->right!=nullptr) q.push(current->right);
              
            }
            flag = 1-flag;
            ans.push_back(level);
        }
        return ans;
    }
};