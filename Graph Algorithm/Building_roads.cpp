#include<iostream>
#include<vector>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
bool visited[MAXN];
vector<int> reps; // One node per connected component

void dfs(int node) {
    visited[node] = true;
    for (int nei : adj[node]) {
        if (!visited[nei])
            dfs(nei);
    }
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

    // Find connected components
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            reps.push_back(i);  // representative of this component
            dfs(i);
        }
    }

    // Output
    int roads_needed = reps.size() - 1;
    cout << roads_needed << "\n";
    for (int i = 1; i < reps.size(); ++i) {
        cout << reps[i - 1] << " " << reps[i] << "\n";
    }

    return 0;
}
