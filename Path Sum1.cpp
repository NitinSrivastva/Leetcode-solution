class Solution {
public:
    bool dfs(TreeNode *root,int tar, int sum) {
        if(root == NULL) return false;
        sum += root->val;
        if (root->left == NULL && root->right == NULL) { // Check if it's a leaf node
            return sum == tar;
        }
        return dfs(root->left , tar , sum) || dfs(root->right , tar , sum);
    }

    bool hasPathSum(TreeNode* root, int tar) {
        if(root == NULL) return false;
        return dfs(root , tar , 0);
    }
};
