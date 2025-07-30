#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long n, k;
        cin >> n >> k;
        bool found = false;

        long long maxY = n / k;
        // Check last 100 values of y (or all if less than 100)
        for (long long y = maxY; y >= max(0LL, maxY - 100); y--) {
            long long left = n - k * y;
            if (left % 2 == 0) {
                found = true;
                break;
            }
        }

        cout << (found ? "YES\n" : "NO\n");
    }

    return 0;
}

