#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> vec(n);
    
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    long long median = vec[n/2];

    long long cost = 0;
    for(auto &x : vec){
        cost += abs(x - median);
    }
    cout << cost << "\n";
    return 0;
}
