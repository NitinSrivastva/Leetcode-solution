class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        map<int , vector<int>> mp;
        vector<int> ans;

        //Fill the map
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                mp[i+j].push_back(mat[i][j]); //map[i+j] use for printing the element of matrix in diagonal way
            }
        }
        
        bool toggle = true;
        for(auto &it : mp){
            if(toggle){
                reverse(it.second.begin() , it.second.end());
            }
            for(int num : it.second){
                ans.push_back(num);
            }
            
            toggle = !toggle;
        }
        return ans;
    }
};
