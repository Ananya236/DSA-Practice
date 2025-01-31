class Solution {
    int directions[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
public:
    int findIsland(vector<vector<int>>& grid, int i, int j, int islandLabel){
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) return 0;

        grid[i][j] = islandLabel;
        int sum = 1;
        for(auto& dir : directions){  
            sum += findIsland(grid, i + dir[0], j + dir[1], islandLabel);
        }
        return sum;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_map<int, int> mp;
        int islandLabel = 2;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    mp[islandLabel] = findIsland(grid, i, j, islandLabel);
                    islandLabel++;
                }
            }
        }

        if(mp.empty()) return (m > 0 && n > 0) ? 1 : 0;

        if(mp.size() == 1) {  
            int islandSize = mp.begin()->second;
            return islandSize == m * n ? islandSize : islandSize + 1;
        }

        int maxIslandSize = 1;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    unordered_set<int> vis;
                    int currIslandSize = 1;

                    for(auto& dir : directions){
                        int x = i + dir[0], y = j + dir[1];
                        if(x >= 0 && x < m && y >= 0 && y < n) {
                            int islandID = grid[x][y];
                            if(islandID && !vis.contains(islandID)) {
                                vis.insert(islandID);
                                currIslandSize += mp[islandID];
                            }
                        }
                    }

                    maxIslandSize = max(maxIslandSize, currIslandSize);
                }
            }
        }
        return maxIslandSize;
    }
};
