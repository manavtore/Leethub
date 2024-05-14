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
    void inorder(TreeNode* root,priority_queue<int,vector<int>,greater<int>>& pq){
        if(root==nullptr) return;
            pq.push(root->val);
            inorder(root->left,pq);
            inorder(root->right,pq);

            return;
    }
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;
        inorder(root,pq);
        while(k!=0){
            ans = pq.top();
            pq.pop();
            k--;
        } 
        return ans;  
    }
};