class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;
        int t = 0;
        for(int i = 0 ; i < m ; i ++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 2 && vis[i][j] != 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
            }
        }
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int tm = q.front().second;
            q.pop();
            t = max(tm,t);
            for(int i  = -1 ; i <= 1 ; i++){
                for(int j = -1 ; j <= 1 ; j++){
                    if(abs(i) + abs(j) == 1){
                        int nrow = row + i ;
                        int ncol = col + j; 
                    if(ncol >= 0 && ncol < n && nrow >= 0 && nrow < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2){
                        q.push({{nrow,ncol},tm+1});
                        vis[nrow][ncol] = 2;
                    }
                    }
                }
            }
        }
        for(int i = 0; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(vis[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return t;
    }
};