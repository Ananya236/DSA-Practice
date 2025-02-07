class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto road: roads){
            int city1 = road[0], city2 = road[1], score = road[2];
            graph[city1].push_back({city2, score});
            graph[city2].push_back({city1, score});
        }

        queue<int> q;
        vector<int> vis(n+1, 0);
        int minScore = INT_MAX;
        q.push(1);
        vis[1] = 1;

        while(!q.empty()){
            int city = q.front();
            q.pop();

            for(auto &[nbrCity, score]: graph[city]){
                minScore = min(minScore, score);
                if(!vis[nbrCity]){
                    vis[nbrCity]=1;
                    q.push(nbrCity);
                }
            }
        }

        return minScore;
    }
};