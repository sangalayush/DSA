class Solution {
   public:
    int countDistinctIslands(vector<vector<int>> &grid) {
        int N = grid.size();
        int M = grid[0].size();
        queue<pair<int, int>> q;
        set<vector<pair<int,int>>> st;      
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                vector<pair<int, int>> sign;
                q.push({i, j});
                grid[i][j] = 0;
                int brow = q.front().first;
                int bcol = q.front().second;
                int calrow = brow - brow;
                int calcol = bcol - bcol;
                sign.push_back({calrow, calcol});
                while (!q.empty()) {
                    int drow[] = {-1, 0, 1, 0};
                    int dcol[] = {0, 1, 0, -1};
                    int row = q.front().first;
                    int col = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nrow = row + drow[k];
                        int ncol = col + dcol[k];
                        if (nrow >= 0 && nrow < N && ncol >= 0 && ncol < M &&
                            grid[nrow][ncol] == 1) {
                            q.push({nrow, ncol});
                            grid[nrow][ncol] = 0;
                            int calrow= nrow-brow;
                            int calcol= ncol-bcol;
                            sign.push_back({calrow,calcol});
                        }
                    }
                }
                st.insert(sign);
            }
        }
        return st.size();
    }
};
//T.C.-> o(R*C)
//S.C.-> O(R*C)
