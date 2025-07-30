#include<vector>
#include<iostream>
using namespace std;

const int LOG = 31;  // Since 2^30 > 10^9
const int N = 2e5 + 5;

int up[N][LOG];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    // Read teleportation mapping (1-based)
    for (int i = 1; i <= n; ++i) {
        cin >> up[i][0];  // 2^0 jump (1 teleport)
    }

    // Build jump table
    for (int j = 1; j < LOG; ++j) {
        for (int i = 1; i <= n; ++i) {
            up[i][j] = up[ up[i][j - 1] ][j - 1];
        }
    }

    // Answer queries
    while (q--) {
        int x;
        long long k;
        cin >> x >> k;

        for (int j = 0; j < LOG; ++j) {
            if (k & (1LL << j)) {
                x = up[x][j];
            }
        }

        cout << x << "\n";
    }

    return 0;
}
