class Solution {
public:
    vector<int>ans;
    void preorder(TreeNode* root , int level){
        if(root == NULL) return;
        if(level == ans.size()) ans.push_back(root->val);
        else{
            ans[level] = max(ans[level] , root->val);
        }
        preorder(root->left,level+1);
        preorder(root->right,level+1);
    }
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) return{};
        preorder(root , 0);
        return ans;
    }
};
