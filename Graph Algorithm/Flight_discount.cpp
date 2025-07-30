#include<vector>
#include<iostream>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct Edge {
    int to;
    ll cost;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    // dist[u][0]: cost to reach u without using coupon
    // dist[u][1]: cost to reach u with using coupon
    vector<vector<ll>> dist(n + 1, vector<ll>(2, INF));
    dist[1][0] = 0;

    // {cost, node, used_coupon}
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> pq;
    pq.push(make_tuple(0, 1, 0));

    while (!pq.empty()) {
        ll currDist = get<0>(pq.top());
        int u = get<1>(pq.top());
        int used = get<2>(pq.top());
        pq.pop();

        if (currDist > dist[u][used]) continue;

        for (auto edge : adj[u]) {
            int v = edge.to;
            ll w = edge.cost;

            // Move without using coupon
            if (dist[v][used] > dist[u][used] + w) {
                dist[v][used] = dist[u][used] + w;
                pq.push(make_tuple(dist[v][used], v, used));
            }

            // Use coupon if not used yet
            if (used == 0) {
                ll discounted = w / 2;
                if (dist[v][1] > dist[u][0] + discounted) {
                    dist[v][1] = dist[u][0] + discounted;
                    pq.push(make_tuple(dist[v][1], v, 1));
                }
            }
        }
    }

    cout << dist[n][1] << "\n";
    return 0;
}

