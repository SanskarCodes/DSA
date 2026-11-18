class Solution {
public:

    bool checkCycle(int node, vector<vector<int>>&adj,vector<int>&vis,vector<int>&dfsvis){
        vis[node] = 1;
        dfsvis[node] = 1;
        for(auto i : adj[node]){
            if(!vis[i]){
                if(checkCycle(i,adj,vis,dfsvis)) return true;
            }
            else if(dfsvis[i]) return true;
        }
        dfsvis[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto i : prerequisites){
            int u = i[1];
            int v = i[0];

            adj[u].push_back(v);
        }
        vector<int>vis(numCourses,0);
        vector<int>dfsvis(numCourses,0);

        for(int i = 0; i < numCourses; i++) {

            if(!vis[i]) {
                if(checkCycle(i, adj, vis, dfsvis))
                    return false;
            }
        }
        return true;
    }
};