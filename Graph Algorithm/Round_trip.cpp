#include<iostream>
#include<vector>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
vector<bool> visited(MAXN);
vector<int> parent(MAXN, -1);

int start = -1, endp = -1;

bool dfs(int node, int par) {
    visited[node] = true;
    for (int nei : adj[node]) {
        if (nei == par) continue; // skip parent
        if (visited[nei]) {
            // Found a cycle
            start = nei;
            endp = node;
            return true;
        } else {
            parent[nei] = node;
            if (dfs(nei, node)) return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Build graph
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Try DFS from every unvisited node
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            if (dfs(i, -1)) break;
        }
    }

    if (start == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // Reconstruct the cycle
    vector<int> cycle;
    cycle.push_back(start);
    for (int v = endp; v != start; v = parent[v]) {
        cycle.push_back(v);
    }
    cycle.push_back(start); // complete the cycle

    cout << cycle.size() << "\n";
    reverse(cycle.begin(), cycle.end());
    for (int node : cycle) {
        cout << node << " ";
    }
    cout << "\n";

    return 0;
}
