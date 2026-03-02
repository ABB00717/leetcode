#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<double> calcEquation(vector<vector<string>> &equations,
                                vector<double> &values,
                                vector<vector<string>> &queries) {
        unordered_map<string, map<string, double>> adj;
        int equations_size = equations.size();
        for (int i = 0; i < equations_size; i++) {
            string l = equations[i][0];
            string r = equations[i][1];

            adj[l][l] = 1;
            adj[r][r] = 1;

            adj[l][r] = values[i];
            adj[r][l] = 1 / values[i];
        }

        for (auto const& [k, valk] : adj) {
            for (auto const& [i, vali] : adj) {
                for (auto const& [j, valj] : adj) {
                    // if i -> k && k -> j then i -> j
                    if (adj[i].count(k) && adj[k].count(j)) {
                        adj[i][j] = adj[i][k] * adj[k][j];
                    }
                }
            }
        }
    
        int queries_size = queries.size();
        vector<double> result(queries_size, -1);
        for (int i = 0; i < queries_size; i++) {
            string l = queries[i][0];
            string r = queries[i][1];

            if (adj.count(l) && adj[l].count(r)) {
                result[i] = adj[l][r];
            }
        }

        return result;
    }
};
