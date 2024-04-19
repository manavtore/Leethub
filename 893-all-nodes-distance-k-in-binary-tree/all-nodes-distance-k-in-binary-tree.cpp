/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void Parents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* Node = q.front();
            q.pop();
            if(Node->left){
                parent[Node->left]=Node;
                q.push(Node->left);
            }
            if(Node->right){
                parent[Node->right]=Node;
                q.push(Node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        Parents(root,parent);

        unordered_map<TreeNode*,bool> mp;
        queue<TreeNode*> q;
        q.push(target);
        mp[target]=true;
        int currentlevel = 0;
        while(!q.empty()){
            if(currentlevel++==k) break;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* Node = q.front();
                    q.pop();
                if(Node->left && !mp[Node->left]){
                    q.push(Node->left);
                    mp[Node->left]=true;
                    
                }
                if(Node->right && !mp[Node->right]){
                    q.push(Node->right);
                    mp[Node->right]=true;
                    
                }
                if(parent[Node] && !mp[parent[Node]]){
                    mp[parent[Node]]=true;
                    q.push(parent[Node]);
                }
            }

        }
        vector<int> result;
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            result.push_back(current->val);
        }
        return result;

    }
};