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
    string smallestString;
    void dfs(TreeNode* root,string& s){
        if(root==nullptr) return;
        s.push_back('a'+root->val);
        if(root->left==nullptr && root->right==nullptr){
            reverse(s.begin(),s.end());
            if(smallestString==""){
                smallestString = s; 
            }else{
                smallestString = min(smallestString,s);
            }
            reverse(s.begin(),s.end());
        }
       dfs(root->left,s);
       dfs(root->right,s);
        s.pop_back();
        return;
    }
    string smallestFromLeaf(TreeNode* root) {
        smallestString="";
        string s="";
        if(root==nullptr) return s;
        dfs(root,s);
        return smallestString;
    }
};