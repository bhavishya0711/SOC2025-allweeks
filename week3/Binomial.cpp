#include<iostream>
using namespace std;

const int MOD = 1e9 + 7;

long long modinv(long long x){
    long long res = 1; 
    long long p = MOD - 2;
    while(p){
        if(p%2) res = res * x % MOD;
        x = x * x % MOD;
        p /= 2;
    }
    return res;
}

long long binomial(int a, int b){
    if(b > a) return 0;
    long long num = 1, den = 1;
    for(int i=0; i<b; i++){
        num = num * (a-i) % MOD;
        den = den * (i+1) % MOD;
    }
    return num * modinv(den) % MOD;
}

int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> vec(n);
    for(int i=0; i<n; i++){
        cin >> vec[i].first >> vec[i].second;
    }
    for(int i=0; i<n; i++){
        int a = vec[i].first;
        int b = vec[i].second;
        cout << binomial(a, b) << "\n";
    }
}
