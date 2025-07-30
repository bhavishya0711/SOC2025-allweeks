#include<iostream>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
vector<int> parent(MAXN, -1);
vector<bool> visited(MAXN, false);

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    parent[start] = -1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int nei : adj[node]) {
            if (!visited[nei]) {
                visited[nei] = true;
                parent[nei] = node;
                q.push(nei);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Read connections
    for (int i = 0; i < m; ++i) {
        int a, b; 
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // BFS from node 1
    bfs(1);

    // If Maija's computer was not visited
    if (!visited[n]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // Reconstruct path from n to 1
    vector<int> path;
    int curr = n;
    while (curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (int node : path) {
        cout << node << " ";
    }
    cout << "\n";

    return 0;
}
