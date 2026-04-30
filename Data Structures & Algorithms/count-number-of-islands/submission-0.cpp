class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int n= grid.size();
        int m= grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>& grid, int i, int j){
        int n= grid.size();
        int m= grid[0].size();

        if(i<0 || i>=n || j<0 ||j>=m || grid[i][j]=='0') return ;

        grid[i][j] = '0';

        int dr[4] = {-1 , 0, 1 ,0};
        int dc[4] = {0, 1, 0, -1};
        for(int k=0; k<4;k++){
            dfs(grid, i+dr[k] , j+dc[k]);
        }



    }
};
