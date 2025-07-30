#include<vector>
#include<iostream>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
vector<int> team(MAXN, 0); // 0 = unvisited, 1 or 2 = team assignment

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    team[start] = 1;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int neighbor : adj[node]) {
            if (team[neighbor] == 0) {
                team[neighbor] = 3 - team[node]; // alternate team: 1 ↔ 2
                q.push(neighbor);
            } else if (team[neighbor] == team[node]) {
                return false; // same team conflict
            }
        }
    }
    return true;
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

    // Check all components
    for (int i = 1; i <= n; ++i) {
        if (team[i] == 0) {
            if (!bfs(i)) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    // Print team assignments
    for (int i = 1; i <= n; ++i) {
        cout << team[i] << " ";
    }
    cout << "\n";

    return 0;
}
