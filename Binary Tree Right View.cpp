class Solution {
public:
    //TC = O(n) &&  SC = O(n)
   //Using DFS
    void preOrder(TreeNode* root, int level, vector<int> &ans) {
        if(root == NULL) {
            return;
        }

        if(ans.size() < level) {
            ans.push_back(root->val);
        }

        preOrder(root->right, level+1, ans);
        preOrder(root->left, level+1, ans); //BT
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        preOrder(root, 1, ans);

        return ans;
    }
};
