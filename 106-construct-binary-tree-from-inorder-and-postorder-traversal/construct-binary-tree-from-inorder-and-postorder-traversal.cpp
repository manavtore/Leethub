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

        return BuildTreeOnce(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
    }
    TreeNode* BuildTreeOnce(vector<int>& postorder,int ps,int pEnd,vector<int>& inorder,int is,int iEnd,map<int,int>& mp){
       if(ps>pEnd || is>iEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[pEnd]);
        int inRoot = mp[root->val];
        int numsleft = inRoot - is;

        root ->left =  BuildTreeOnce(postorder,ps,ps+numsleft-1,inorder,is,inRoot-1,mp);
        root ->right = BuildTreeOnce(postorder,ps+numsleft,pEnd-1,inorder,inRoot+1,iEnd,mp);

        return root;
    }
};