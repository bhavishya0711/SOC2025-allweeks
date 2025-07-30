#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N], parent(N), visited(N), inStack(N);
int start = -1, endCycle = -1;

bool dfs(int u) {
    visited[u] = 1;
    inStack[u] = 1;

    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            if (dfs(v)) return true;
        }
        else if (inStack[v]) {
            start = v;
            endCycle = u;
            return true;
        }
    }

    inStack[u] = 0;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i] && dfs(i)) {
            // Cycle found
            vector<int> cycle;
            cycle.push_back(start);
            for (int v = endCycle; v != start; v = parent[v])
                cycle.push_back(v);
            cycle.push_back(start);
            reverse(cycle.begin(), cycle.end());

            cout << cycle.size() << "\n";
            for (int x : cycle) cout << x << " ";
            cout << "\n";
            return 0;
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
