class Solution {
public:
    void dfs(vector<vector<int>> &rooms, vector<int> &vis, int node){
        vis[node] = 1;
        
        for(int i: rooms[node]){
            if(!vis[i]) dfs(rooms, vis, i);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size(), 0);
        
        dfs(rooms, vis, 0);
        
        for(int i: vis) if(!i) return false;
        
        return true;
    }
};