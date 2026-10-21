class Solution{
public:
    vector<vector<int>> nearest(vector<vector<int>> grid){
        int N= grid.size();
        int M= grid[0].size();
        vector<vector<int>> vis(N,vector<int> (M,0));
        vector<vector<int>> dis(N,vector<int> (M,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int row= q.front().first.first;
            int col= q.front().first.second;
            int steps =q.front().second;
            q.pop();
            dis[row][col]= steps;
            int drow[]= {-1,0,1,0};
            int dcol[]= {0,1,0,-1};
            for(int i=0;i<4;i++){
                int nrow= row+ drow[i];
                int ncol= col+ dcol[i];
                if(nrow>=0 && nrow<N && ncol>=0 && ncol<M && vis[nrow][ncol]==0){
                    q.push({{nrow,ncol},steps+1});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return dis;
    }
};
//T.C.->O(R*C)
//S.C.->O(R*C)
