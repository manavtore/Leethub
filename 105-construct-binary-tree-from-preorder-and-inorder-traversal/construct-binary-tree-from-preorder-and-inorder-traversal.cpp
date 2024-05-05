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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }

        TreeNode* root = tree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }

    TreeNode* tree(vector<int>& preorder,int prestart,int preEnd,vector<int>& inorder,int instart,int inEnd,map<int,int>& mp){
        if(prestart>preEnd || instart>inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[prestart]);

        int inele = mp[root->val];
        int numsleft = inele - instart;

        root->left = tree(preorder,prestart+1,prestart+numsleft,inorder,instart,inele-1,mp);
        root->right = tree(preorder,prestart+numsleft+1,preEnd,inorder,inele+1,inEnd,mp);

        return root;
    }
};