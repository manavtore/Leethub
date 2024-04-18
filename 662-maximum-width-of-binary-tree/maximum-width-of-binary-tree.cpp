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
    int widthOfBinaryTree(TreeNode* root) {
        int ans =0;
        if(root==nullptr) return ans;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            long long mini = q.front().second;
             long long first,last;
            for(int i=0;i<size;i++){
                long long current_index = q.front().second-mini;
                TreeNode* Node = q.front().first;
                q.pop();
                
                if(i==0) first=current_index;
                if(i==size-1) last = current_index;
                if(Node->left){
                    q.push({Node->left,current_index*2+1});
                }
                if(Node->right){
                    q.push({Node->right,current_index*2+2});
                }
 
            }
            ans = max(ans,static_cast<int>(last-first+1));
        }
        return ans;
    }
};