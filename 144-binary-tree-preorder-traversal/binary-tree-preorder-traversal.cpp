class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr) return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();

            ans.push_back(node->val);
            if(node->right != nullptr) st.push(node->right);
            if(node->left != nullptr ) st.push(node->left);
            
           
        }
        
        return ans;

    }
};