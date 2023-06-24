class Solution {
public:
    int find(vector<int>& parents, int curr) {
        if (parents[curr] == curr) return curr;
        return parents[curr] = find(parents, parents[curr]);  // Path compression
    }

    void merge(int dest, int curr, vector<int> &parents) {
        int p1 = find(parents, dest);
        int p2 = find(parents, curr);
        parents[p2] = p1;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<int> parents(accounts.size(), -1);
        map<string, int> mp;

        for (int i = 0; i < accounts.size(); i++) {
            parents[i]=i;
            for (int j = 1; j < accounts[i].size(); j++) {
                if (mp.find(accounts[i][j]) != mp.end()) {
                    merge(mp[accounts[i][j]], i, parents);
                } else {
                    mp[accounts[i][j]] = i;
                }
            }
        }

        vector<vector<string>> result;
        map<int, vector<string>> temp;
        for (auto& i : mp) {
            int parent = find(parents, i.second);
            cout<<parent;
            if (temp[parent].empty())
                temp[parent].push_back(accounts[parent][0]);
            temp[parent].push_back(i.first);
        }

        for (auto& i : temp) {
            result.push_back(i.second);
        }

        return result;
    }
};
