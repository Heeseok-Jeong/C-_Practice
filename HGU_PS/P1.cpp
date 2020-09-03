#include <iostream>
#include <math.h>
using namespace std;

int solve(int x) {
  int i, y, temp, mod, pp;
  float exp;
  i = 0;
  y = 0;

  for(i = 0; i <= x; i++) {
    if(x == 0) {
      return i;
    }

    temp = y;
    exp = 0.0;
    while(temp != 0) {
      mod = temp%10;
      temp /= 10;
      if(mod == 4) {
        pp = int(pow(10.0, exp));
        y += pp;
      }
      exp++;
    }

    if(y == x) {
      return i;
    }

    y++;
  }
  return -1;
}

int main() {
  int x, result;
  cin >> x;
  result = solve(x);
  cout << result << endl;
  return 0;
}
