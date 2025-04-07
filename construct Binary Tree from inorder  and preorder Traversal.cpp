class Solution {
public:
    TreeNode* build(vector<int>& in , int inlo , int inhi , vector<int>& post , int postlo , int posthi){
        if(inlo > inhi) return NULL;
        TreeNode* root = new TreeNode(post[posthi]);
        if(inlo == inhi) return root;

        int i = inlo;
        while(i <= inhi){
            if(in[i] == post[posthi]) break;
            i++;
        }

        int leftcount  = i - inlo;
        int rightcount = inhi - i;

        root->left = build(in , inlo , i-1 , post , postlo , postlo+leftcount-1 );
        root->right = build(in , i+1 , inhi , post , postlo+leftcount , posthi-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n = in.size();
        return build(in , 0 , n-1 , post , 0 , n-1);
    }
};
