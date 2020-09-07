#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;

int solve(string x) {
  int i, j, temp, diff, n, y, size_;
  float exp;
  size_ = x.size();
  diff = 0;
  for(i = 0; i < size_; i++) {
    // cout << "i : " << i << endl;
    n = int(x[i])-48;
    // cout << "n : " << n << endl;
    temp = 0;

    if(i == size_ - 1) {
      if(n > 4) {
        temp = 1;
      }
    } else {
      if(n > 4) {
        diff += int(pow(10.0, size_ - 1 - i));
        n--;
      }
      for(j = size_ - 2 - i; j >= 0; j--) {
        // cout << "j : " << j << endl;
        temp += (int(pow(10.0, j)) * int(pow(9.0, size_-i-2-j)));
        // cout << "temp : " << temp << endl;
      }
      temp *= n;
    }
    diff += temp;
    // cout << "total temp : " << temp << endl;
  }
  // cout << "diff : " << diff << endl;
  y = stoi(x);
  y -= diff;
  return y;
}

int main() {
  int result;
  string x;

  cin >> x;
  // scanf("%d", &x);
  result = solve(x);
  // cout << result << endl;
  printf("%d\n", result);
  return 0;
}
