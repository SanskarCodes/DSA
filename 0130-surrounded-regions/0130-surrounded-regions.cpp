
class Solution {
public:

    void dfs(int row, int col, int m, int n,
             vector<vector<char>>& board,
             vector<vector<int>>& vis) {

        vis[row][col] = 1;

        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {

                if(abs(i) + abs(j) == 1) {

                    int nrow = row + i;
                    int ncol = col + j;

                    if(nrow >= 0 && nrow < m &&
                       ncol >= 0 && ncol < n &&
                       !vis[nrow][ncol] &&
                       board[nrow][ncol] == 'O') {

                        dfs(nrow, ncol, m, n, board, vis);
                    }
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        // First and last columns
        for(int i = 0; i < m; i++) {

            if(board[i][0] == 'O' && !vis[i][0]) {
                dfs(i, 0, m, n, board, vis);
            }

            if(board[i][n-1] == 'O' && !vis[i][n-1]) {
                dfs(i, n-1, m, n, board, vis);
            }
        }

        // First and last rows
        for(int j = 0; j < n; j++) {

            if(board[0][j] == 'O' && !vis[0][j]) {
                dfs(0, j, m, n, board, vis);
            }

            if(board[m-1][j] == 'O' && !vis[m-1][j]) {
                dfs(m-1, j, m, n, board, vis);
            }
        }

        // Convert surrounded regions
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
