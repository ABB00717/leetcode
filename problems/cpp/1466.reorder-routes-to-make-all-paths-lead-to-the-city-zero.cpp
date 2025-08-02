#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int result = 0;
        vector<vector<int>> dest_to_src(n, vector<int>());
        vector<vector<int>> src_to_dest(n, vector<int>());

        for (const vector<int>& connection : connections) {
            const int src = connection[0];
            const int dest = connection[1];
            dest_to_src[dest].push_back(src);
            src_to_dest[src].push_back(dest);
        }

        stack<int> next;
        vector<bool> visited(n, false);
        next.push(0);
        while (!next.empty()) {
            const int src = next.top();
            next.pop();
            visited[src] = true;
            
            for (const int& node : src_to_dest[src]) {
                if (!visited[node]) {
                    result++;
                    next.push(node);
                }
            }

            for (const int& node : dest_to_src[src]) {
                if (!visited[node]) {
                    next.push(node);
                }
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> connections = {{4,5},{0,1},{1,3},{2,3},{4,0}};
    solution.minReorder(6, connections);
}
