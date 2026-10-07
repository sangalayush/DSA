class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<char>>& grid) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int m= grid.size();
        int n= grid[0].size();
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int drow = -1; drow <= 1; drow++) {
                int nrow = row + drow;
                int ncol = col;
                if (nrow >= 0 && nrow <m && ncol >= 0 && ncol <n &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
            for (int dcol = -1; dcol <= 1; dcol++) {
                int nrow = row;
                int ncol = col + dcol;
                if (nrow >= 0 && nrow <m && ncol >= 0 && ncol <n &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int row = 0; row <m; row++) {
            for (int col = 0; col <n; col++) {
                if (!vis[row][col] && grid[row][col] == '1') {
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
    }
};
//T.C.->O(M*N)
//S.C.->O(M*N)
//THE ABOVE ONE IS FOR ONLY HORIZONTAL & VERTICAL NEIGHBOR LANDS

//THE BELOW ONE IS FOR HORIZONTAL & VERTICAL & DIAGONAL NEIGHBOR LANDS
void bfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<char>>& grid) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int m = grid.size();
        int n = grid[0].size();
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int drow = -1; drow <= 1; drow++) {
                for (int dcol = -1; dcol <= 1; dcol++) {
                    int nrow = row + drow;
                    int ncol = col + dcol;
                    if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                        !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }
