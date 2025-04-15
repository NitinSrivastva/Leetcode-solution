class Solution {
public:
  //Inorder using Morrish algorithm 
    vector<int>inorder(TreeNode* root , vector<int>& ans){
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left != NULL){ // it means currrent exists
                TreeNode* pred = curr->left;
                while(pred->right != NULL && pred->right != curr){
                    pred = pred->right;
                }

                if(pred->right == NULL){ // link kr do 
                    pred->right = curr;
                    curr = curr->left;
                }

                else{ // unlink
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
            else{
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }
    bool isValidBST(TreeNode* root) {
        vector<int>ans;
        inorder(root , ans);
        for(int i = 1; i<ans.size();i++){
            if(ans[i] <= ans[i-1]) return false;
        }
        return true;
    }
};
