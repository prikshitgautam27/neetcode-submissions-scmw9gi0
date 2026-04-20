class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
 queue<pair<pair<int,int>,int>>q;

int cntfresh=0;

//counting the fresh and pushing rotten oranges in q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (grid[i][j]==2){
                    q.push({{i,j},0});

                }
                if(grid[i][j]==1){
                    cntfresh+=1;
                }
            }
        }

// taken every element from q and visiting the neighbours

int delr[4]={-1,0,1,0};
int delc[4]={0,1,0,-1};
int tm=0;
int cnt=0;// rotten from fresh count;

while(!q.empty()){
 
auto it=q.front();
int r=it.first.first;
int c=it.first.second;
int t=it.second;
  tm=max(tm,t);
q.pop();


for(int i=0;i<4;i++){
    int nrow = r + delr[i];
    int ncol = c + delc[i];

    if(nrow>=0 && ncol>=0 && nrow< n && ncol<m && grid[nrow][ncol]==1 ){
        q.push({{nrow,ncol},tm+1});
        grid[nrow][ncol]=2;
        cnt+=1;
    }
}






}



return (cnt== cntfresh) ? tm : -1;
    }
};
