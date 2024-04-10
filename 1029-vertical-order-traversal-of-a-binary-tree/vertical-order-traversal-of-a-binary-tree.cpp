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
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto current = q.front();
            q.pop();

            TreeNode* N = current.first;
            

            int x = current.second.first;
            int y = current.second.second;

            mp[x][y].insert(N->val);

            if(N->left!=nullptr){
                q.push({{N->left},{x-1,y+1}});
            }
            if(N->right!=nullptr){
                q.push({{N->right},{x+1,y+1}});
            }
        }


        vector<vector<int>> ans;
        for(auto c: mp){
            vector<int> col;
             for(auto cu:c.second){
                col.insert(col.end(),cu.second.begin(),cu.second.end());
             }
             ans.push_back(col);
        }
        return ans;
    }
};