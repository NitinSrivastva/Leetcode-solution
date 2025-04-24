class Solution {
public:
    int n , m;

    void checkgrid(vector<vector<char>>& grid , int i , int j){
        //base case
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != '1') return;

        grid[i][j] = '$';

        checkgrid(grid , i - 1 , j);
        checkgrid(grid , i + 1 , j);
        checkgrid(grid , i  , j - 1);
        checkgrid(grid , i  , j + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;

        n = grid.size();
        m = grid[0].size();

        for(int i = 0 ; i < n ; i++){
            for(int  j = 0 ; j < m ; j++){
                if(grid[i][j] == '1'){
                    checkgrid(grid , i , j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
