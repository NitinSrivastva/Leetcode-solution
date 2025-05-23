class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>>ans;
       if(root == NULL) return ans;
       queue<TreeNode*>q;
       q.push(root);
       while(q.size() > 0){
            int size = q.size();
            vector<int>level;
            for(int i =1;i<=size;i++){
                TreeNode* temp = q.front();
                q.pop();
                level.push_back(temp->val);

                if(temp->left != NULL) q.push(temp->left); 
                if(temp->right != NULL) q.push(temp->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
