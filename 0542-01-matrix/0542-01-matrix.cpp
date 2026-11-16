
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans(m, vector<int>(n, -1));

        queue<pair<int,int>> q;

        // Step 1: Push all zeroes into queue
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(mat[i][j] == 0) {
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        // Step 2: Multi-source BFS
        while(!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++) {

                int nrow = row + dx[i];
                int ncol = col + dy[i];

                if(nrow >= 0 && nrow < m &&
                   ncol >= 0 && ncol < n &&
                   ans[nrow][ncol] == -1) {

                    ans[nrow][ncol] = ans[row][col] + 1;

                    q.push({nrow,ncol});
                }
            }
        }

        return ans;
    }
};
