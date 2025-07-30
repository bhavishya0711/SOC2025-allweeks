#include<vector>
#include<iostream>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

vector<int> adj[N];
int inDeg[N];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        inDeg[b]++;
    }

    // Topological Sort (Kahn's algorithm)
    vector<int> topo;
    queue<int> q;

    for (int i = 1; i <= n; ++i)
        if (inDeg[i] == 0)
            q.push(i);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : adj[u]) {
            if (--inDeg[v] == 0)
                q.push(v);
        }
    }

    // Count number of paths
    vector<int> ways(n + 1, 0);
    ways[1] = 1;

    for (int u : topo) {
        for (int v : adj[u]) {
            ways[v] = (ways[v] + ways[u]) % MOD;
        }
    }

    cout << ways[n] << "\n";
    return 0;
}

