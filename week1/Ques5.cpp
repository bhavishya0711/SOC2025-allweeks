#include <iostream>
using namespace std;

int main() {
  long long n;
  cin >> n;
  long long val = n;
  cout<< val << " ";
  
  while(val!= 1){
    if (val%2 == 0) {
      val = val/2;
      cout << val << " ";
    }
    else {
      val = 3 * val + 1;
      cout << val << " ";
    }
  }
  return 0;
}
