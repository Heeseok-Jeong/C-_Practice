#include <iostream>
using namespace std;

void hanoi(int n, int s, int e, int l) {
  if(n == 1) {
    printf("%d %d\n", s, e);
    return;
  }
  hanoi(n-1, s, l, e);
  printf("%d %d\n", s, e);
  hanoi(n-1, l, e, s);
}

int main() {
  int n, s, e, l;
  s = 1;
  e = 3;
  l = 2;

  scanf("%d", &n);

  int size_ = (1<<n)-1;
  printf("%d\n", size_);

  hanoi(n, s, e, l);
  return 0;
}
