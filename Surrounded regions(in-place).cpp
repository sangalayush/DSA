class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int M = board.size();
        int N = board[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (i == 0 || i == M-1 || j == 0 || j == N-1) {
                    if (board[i][j] == 'O') {
                        q.push({i, j});
                        board[i][j]='a';
                    }
                }
            }
        }
        while (!q.empty()) {
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow>=0 && nrow<M && ncol>=0 && ncol<N && board[nrow][ncol]=='O'){
                    q.push({nrow,ncol});
                    board[nrow][ncol]='a';
                } 
            }
        }
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='a')
                    board[i][j]='O';
            }
        }
    }
};
//T.C.-> Overall it is O(R*C)
//S.C.-> O(R*C)-> For storing the elements in the queue in worst case it can be this.
