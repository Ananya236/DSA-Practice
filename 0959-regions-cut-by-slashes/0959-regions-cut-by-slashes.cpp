class Solution {
public:
    static void dfs(int v, vector<vector<int>>& adj, bitset<962>& viz) {
        viz[v] = 1;
        for (int w : adj[v]) {
            if (viz[w]) continue;
            dfs(w, adj, viz);
        }
    }
    static int regionsBySlashes(vector<string>& grid) {
        const int n = grid.size();
        const int side = n+1; // side length of the extended grid
        const int N = side*side; // total vertices in the extended grid

        bitset<962> viz = 0; // Supports up to a 31x31 grid
        vector<vector<int>> adj(N);

        int N0 = N-side;
        for (int i = 0; i < n; i++) {
            adj[i].push_back(i+1);             // Top border
            adj[i+1].push_back(i);

            adj[i+N0].push_back(i+N0+1);   // Bottom border
            adj[i+N0+1].push_back(i+N0);

            adj[i*side].push_back((i+1)*side);    // Left border
            adj[(i+1)*side].push_back(i*side);

            adj[n+i*side].push_back(n+(i+1)*side); // Right border
            adj[n+(i+1)*side].push_back(n+i*side);
        }

        int E = 4*n; // Initial edges from the borders

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '\\') {
                    int u = i*side+j;
                    int v = (i+1)*side+j+1;
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                    E++;
                } 
                else if (grid[i][j] == '/') {
                    int u = i*side+j+1;
                    int v = (i+1)*side+j;
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                    E++;
                }
            }
        }

        int component = 0;
        for (int i=0; i < N; i++)
            // don't count isolated 1-vertex components
            if (!adj[i].empty() && !viz[i]) {
            //    cout << "\nStarting DFS for component at vertex: "<<i<<endl;
                component++;
                dfs(i, adj, viz);
            }
        
        int V = viz.count();
        int F = E-V+1+component;
        
        // output
       // cout<<"V="<<V<<", E="<<E<<", component="<<component<<", F="<<F<< endl;
        //print(grid);
        return F - 1; // Final face count
    }
};