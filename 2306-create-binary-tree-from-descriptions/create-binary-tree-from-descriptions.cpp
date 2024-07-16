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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_map<int,bool> hasparent;

        for(auto desc:descriptions){
            int parentval=desc[0],childval=desc[1],isleft=desc[2];
            TreeNode*  parentNode = nullptr;
            TreeNode* childNode = nullptr;

            if(mp.find(parentval)==mp.end()) parentNode = new TreeNode(parentval);
            else parentNode = mp[parentval];

            if(mp.find(childval)==mp.end()) childNode = new TreeNode(childval);
            else childNode = mp[childval];

            if(isleft) parentNode->left = childNode;
            else parentNode->right = childNode;

            hasparent[childval]=true;
            mp[childval]=childNode;
            mp[parentval]=parentNode;
        }
        TreeNode* root = nullptr;
        for(auto& [Nodeval,Node]:mp){
            if(!hasparent[Nodeval]){
                root = Node;
                break;
            }
        }
        return root;
    }
};