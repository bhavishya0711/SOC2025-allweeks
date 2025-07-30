#include<iostream>
#include<vector>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

ll power(ll x, ll n){
    if(n == 0) return 1;
    ll temp = power(x, n / 2);
    temp %= MOD;

    if(n % 2 == 0){
        return (temp * temp) % MOD;
    } else {
        return (x % MOD * temp % MOD * temp % MOD) % MOD;
    }
}


ll exponentiation(int a, int b, int c){
    if(a == 0 && b == 0 && c == 0) return 1; // 0^0^0 is defined as 1 in problem
    if(a == 0) return 0;

    ll exp = power(b, c) % (MOD-1);
    return power(a, exp) % MOD;
}

int main(){
    int n;
    cin >> n;
    int a, b, c;
    vector<ll> result;
    for(int i=0; i<n; i++){
        cin >> a >> b >> c;
        result.push_back(exponentiation(a, b, c));
    }
    for(auto in : result){
        cout << in << endl;
    }

}
