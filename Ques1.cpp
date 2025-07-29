#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  long long sum = 0;
  
  for (int i = 0; i < n-1; i++){
    int t;
    cin >> t;
    sum = sum + t;
  }
  
  long long sum1 = 1LL * n * (n+1)/2;
  
  cout << sum1 - sum;
  return 0;
}
