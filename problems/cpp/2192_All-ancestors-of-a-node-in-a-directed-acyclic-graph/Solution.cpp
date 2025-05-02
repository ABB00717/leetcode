class Solution {
private:
    void findAncestors(int node, vector<vector<int>>& children, vector<bool>& visited, vector<int>& ancestors) {
        visited[node] = true;

        for (auto ancestor : children[node]) {
            if (!visited[ancestor]) {
                ancestors.push_back(ancestor);
                findAncestors(ancestor, children, visited, ancestors);
            }
        }
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ancestors(n);
        vector<vector<int>> children(n);

        for (auto edge : edges) {
            children[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            findAncestors(i, children, visited, ancestors[i]);
            std::sort(ancestors[i].begin(), ancestors[i].end(), std::less<int>());
        }

        return ancestors;
    }
};