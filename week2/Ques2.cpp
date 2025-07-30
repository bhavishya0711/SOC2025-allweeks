#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;

    vector<long long> arr(n);
    unordered_map<long long, int> mpp; // value -> index

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; ++i) {
        long long need = x - arr[i];
        if (mpp.count(need)) {
            cout << mpp[need] + 1 << " " << i + 1 << "\n";
            return 0;
        }
        mpp[arr[i]] = i;
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}

