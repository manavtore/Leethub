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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> mp;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* N = it.first;
            int x = it.second.first;
            int y = it.second.second;

            mp[x][y].insert(N->val);
            if(N->left!=nullptr){
                q.push({N->left,{x-1,y+1}});
            }
            if(N->right!=nullptr){
                q.push({N->right,{x+1,y+1}});
            }
        }

        for(auto co:mp){
            vector<int> col;
            for(auto c: co.second){
                col.insert(col.end(),c.second.begin(),c.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};