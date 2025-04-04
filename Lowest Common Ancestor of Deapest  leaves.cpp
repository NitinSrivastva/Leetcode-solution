class Solution {
public:
    int levels(TreeNode* root) {

        if (root == NULL) return 0;

        return 1 + max(levels(root->right), levels(root->left));
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
        if (root == NULL) return NULL;
        
        if (levels(root->right) == levels(root->left))
            return root;
        
        if (levels(root->right) > levels(root->left)) 
            return lcaDeepestLeaves(root->right);
        
        else 
            return lcaDeepestLeaves(root->left);
    }
};
