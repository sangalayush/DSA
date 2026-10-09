class Solution{
public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int m= grid.size();
        int n= grid[0].size();
        int vis[m][n]={0};
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0||j==0||i==n-1||j==m-1){
                    if(grid[i][j]==1){
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }
        while(!q.empty()){
            int row= q.front().first;
            int col= q.front().second;
            q.pop();
            int drow[]={-1,0,1,0};
            int dcol[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nrow= row+drow[i];
                int ncol= col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        //check and count the no of lands that cannot walkoff the grid boundary
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
//T.C.-?O(R*C) for checking the boundary land elements+ O(R*C*4) for checking neighboring elements in the queue(in worst case it will R*C 1 1 1 1
//                                                                                                                                        1 1 1 1) + O(R*C) for 
//checking the land elememts bounded by water.
//OVERALL T.C.~ O(R*C)
//S.C.->O(R*C) for storing elements in queue in worst case + O(R*C) for storing visited array->S.C.~ O(R*C).
