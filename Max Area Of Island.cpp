class Solution {
public:
    int n , m;

    int checkgrid(vector<vector<int>>& grid , int i , int j){
        //base case
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != 1) return 0;

        grid[i][j] = '$';

        int area = 1;

        area += checkgrid(grid , i - 1 , j);
        area += checkgrid(grid , i + 1 , j);
        area += checkgrid(grid , i  , j - 1);
        area += checkgrid(grid , i  , j + 1);

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea = 0;
        n = grid.size();
        m = grid[0].size();

        for(int i = 0 ; i < n ; i++){
            for(int  j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    int area = checkgrid(grid , i , j);
                    maxarea = max(maxarea , area);
                }
            }
        }
        return maxarea;
    }
};
