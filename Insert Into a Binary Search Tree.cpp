class Solution {
public:

    void insert(TreeNode* root, int val){
        if(root == NULL) root = new TreeNode(val);
        else if(root->val > val){
            if(root->left == NULL){
                root->left = new TreeNode(val);
            }
            else insert(root->left , val);
        }
        else{
            if(root->right == NULL){
                root->right = new TreeNode(val);
            }
            else insert(root->right , val);
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return root = new TreeNode(val);

        insert(root , val);
        return root;
    }
};
