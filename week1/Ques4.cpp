#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int LuckyNumber(int x){
  int min_digit = 9, max_digit = 0;
  
  while(x>0){
    int d = x%10;
    min_digit = min(min_digit, d);
    max_digit = max(max_digit, d);
    x = x/10;
  }
  return max_digit - min_digit;
}

int main() {
  int t;
  cin >> t;
  
  while(t--){
    int l, r;
    cin >> l >> r;
    
    int best = l;
    int max_luck = LuckyNumber(l);
    
    for(int i = l; i <= min(r, l+100); i++){
      int curr_luck = LuckyNumber(i);
      if(curr_luck>max_luck){
        max_luck = curr_luck;
        best = i;
      }
      if(max_luck == 9){break;}
    }
    cout << best << "\n";
  }
  return 0;
}
