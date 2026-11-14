class Solution {
public:
    void dfs(vector<vector<int>>& image, vector<vector<int>>&vis,int initial_color,int color,int sr,int sc){
        if(!vis[sr][sc]){
            vis[sr][sc] = 1;
        }
        int n = image.size();
        int m = image[0].size();
        if(image[sr][sc] == initial_color){
            image[sr][sc] = color;
        }
        for(int i = -1 ; i <= 1 ; i++){
            for(int j = -1 ; j <= 1 ; j++){
                if(abs(i)+abs(j)==1){
                    int nrow = sr + i;
                    int ncol = sc + j;
                    if(ncol>=0 && ncol < m && nrow >= 0 && nrow < n && image[nrow][ncol] == initial_color && !vis[nrow][ncol]){
                        dfs(image,vis,initial_color,color,nrow,ncol);
                    }
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,int sr, int sc, int color) {
        int initial_color = image[sr][sc];
        if(initial_color == color) return image;
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        dfs(image,vis,initial_color,color,sr,sc);
        return image;
    }
};