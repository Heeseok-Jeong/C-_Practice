#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> disk_info;
int top_rod[4];

int rec(int x, int s, int d, int r, int count) {
  if(x > 0)  {
    if(s == d) {
      count = rec(x-1, disk_info[x-1], d, 6-disk_info[x-1]-d, count);
    } else {
      if(!((top_rod[s] == x) && (top_rod[d] > x))) {
        count = rec(x-1, disk_info[x-1], r, 6-disk_info[x-1]-r, count);
      }
      count += int(pow(2.0, x-1));
    }
  }
  return count;
}

int main() {
  int i, j, n, k, temp, len, result = 0;
  scanf("%d %d", &n, &k);
  disk_info.resize(n+1);
  for(i = 1; i < 4; i++) {
    scanf("%d", &len);
    temp = 0;
    for(j = 0; j < len; j++) {
      scanf("%d", &temp);
      disk_info[temp] = i;
    }
    top_rod[i] = temp;
  }

  result = rec(n, disk_info[n], k, 6-disk_info[n]-k, result);
  printf("%d\n", result);
}
