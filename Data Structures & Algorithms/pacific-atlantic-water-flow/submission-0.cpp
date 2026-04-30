class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n= heights.size();
        int m= heights[0].size();
        vector<vector<int>>res;
        vector<vector<bool>>atlantic(n,vector<bool>( m,false));
        vector<vector<bool>>pacific(n,vector<bool>( m,false));


        for(int i=0; i<n ;i++){
            // left
            dfs(heights, pacific, i, 0, heights[i][0]);
            // right
            dfs(heights, atlantic, i,m-1, heights[i][m-1]);
        }



        for(int j=0; j<m; j++){
            // top
            dfs(heights, pacific, 0,j , heights[0][j]);
            // bottom
            dfs(heights, atlantic, n-1,j, heights[n-1][j]);
            

        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(atlantic[i][j] && pacific[i][j]){
                    res.push_back({i,j});
                }
            }
        }



return res;
    }

void dfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, int i, int j, int preheit ){
        int n= heights.size();
        int m= heights[0].size();
        if(i<0 || i>=n || j>=m || j<0 || vis[i][j] ) return ;
        if(heights[i][j]< preheit) return ;

vis[i][j]= true;
int dr[4] ={-1, 0,1 ,0};
int dc[4] = {0, 1, 0 ,-1};

        for(int k=0; k<4; k++){
            dfs(heights, vis, i+ dr[k] , j+ dc[k], heights[i][j]);
        }



}

};
