class Solution {
    int directions[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n){
        if(i<0 || i>=m || j<0 || j>=n || !grid[i][j]) return 0;

        int sum = grid[i][j];
        grid[i][j] = 0; //marking as vis

        for(int* dir: directions){
            sum += dfs(grid, i+dir[0], j+dir[1], m, n);
        }
        return sum;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int maxFishes = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    int currFishes = dfs(grid, i, j, m, n);
                    maxFishes = max(maxFishes, currFishes);
                }
            }
        }

        return maxFishes;
    }
};