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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()) return nullptr;

        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }

        return buildTreeOnce(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
    }
    TreeNode* buildTreeOnce(vector<int>& inorder,int instart,int inEnd,vector<int>& postorder,int pStart,int pEnd,map<int,int>& mp){
        if(instart>inEnd || pStart>pEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[pEnd]);
        int inRoot = mp[root -> val];
        int numsleft = inRoot - instart;

        root->left = buildTreeOnce(inorder,instart,inRoot-1,postorder,pStart,pStart+numsleft-1,mp);
        root->right = buildTreeOnce(inorder,inRoot+1,inEnd,postorder,pStart+numsleft,pEnd-1,mp);
        return root;
    }
};