class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int leftH = minDepth(root->left);
        int rightH = minDepth(root->right);

        if(root->left == NULL){
            int currH = 1 + max(leftH , rightH);
            return currH;
        }

        if(root->right == NULL){
            int currH = 1 + max(leftH , rightH);
            return currH;
        }
        int currH = min(leftH , rightH) + 1;
        return currH;
    }
};
