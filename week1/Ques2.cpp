#include<bits/stdc++.h>
using namespace std;

int main(){
  string str;
  cin >> str;
  int times = 1;
  int max_len = 1;
  
  for ( int  i= 1; i < str.size() ; i++){
    if(str[i] == str[i-1]){
      times += 1;
      max_len = max(max_len, times);
    }
    else times = 1;
  }
  
  cout << max_len;
  return 0;
}
