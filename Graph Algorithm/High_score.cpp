#include<vector>
#include<iostream>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct Edge {
    int u, v;
    ll w;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};  // no negation this time
    }

    vector<ll> dist(n + 1, -INF);
    dist[1] = 0;

    // Bellman-Ford for longest path
    for (int i = 0; i < n - 1; ++i) {
        for (const auto& e : edges) {
            if (dist[e.u] != -INF && dist[e.u] + e.w > dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // Check for positive cycle reachable from node 1 to node n
    vector<bool> affected(n + 1, false);
    for (int i = 0; i < n; ++i) {
        for (const auto& e : edges) {
            if (dist[e.u] != -INF && dist[e.u] + e.w > dist[e.v]) {
                dist[e.v] = INF;
                affected[e.v] = true;
            }
        }
    }

    if (dist[n] == INF) cout << -1 << "\n";
    else cout << dist[n] << "\n";

    return 0;
}
