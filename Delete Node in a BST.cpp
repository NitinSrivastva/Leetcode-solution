class Solution {
public:
    //Finding the predecessor of inorder
    TreeNode* iop(TreeNode* root){
        TreeNode* pred = root->left;
        while(pred->right != NULL){
            pred = pred->right;
        }
        return pred;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        if(root->val == key){
            //case 1: With no child;
            if(root->left == NULL && root->right == NULL) return NULL;

            // case 2 : with One child Node 
            if(root->left == NULL || root->right == NULL){
                if(root->left != NULL) return root->left;
                else return root->right;
            }

            // Case 3 : with Two child nodes 
            if(root->left != NULL && root->right != NULL){
                //replace the root with its inorder predecessor/successor
                //after replacing delete the predecessor/successor
                TreeNode* pred = iop(root);
                root->val = pred->val;
                root->left = deleteNode(root->left , pred->val);
            }
        }

        else if(root->val > key){ // go left 
            root->left = deleteNode(root->left , key);
        }
        else{ // go right
            root->right  = deleteNode(root->right , key);
        }
        return root;
    }
};
