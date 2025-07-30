#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> song(n);  // Correct declaration
    
    for (int i = 0; i < n; ++i) {
        cin >> song[i];
    }
    
    unordered_set<int> songSet;
    int left = 0, maxlen = 0;
    
    for (int right = 0; right < n; ++right) {
        while (songSet.count(song[right])) {
            songSet.erase(song[left]);
            left++;
        }
        songSet.insert(song[right]);
        maxlen = max(maxlen, right - left + 1);
    }
    
    cout << maxlen << endl;
    return 0;
}
