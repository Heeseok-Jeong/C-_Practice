#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> disk_info;
int top_rod[4];

int rec(int x, int s, int d, int r, int count) {
  if(x > 0)  {
    if(s == d) {
      count = rec(x-1, disk_info[x-1], d, r, count);
    } else {
      if(!((top_rod[disk_info[s]] == x)) && (top_rod[disk_info[d]] <= x)) {
        count = rec(x-1, disk_info[x-1], r, d, count);
      }

      if(s == r) {
        count += (int(pow(2.0, x)) - 1);
      } else {
        count += int(pow(2.0, x-1));
      }
    }
  }
  return count;
  // if(!((top_rod[disk_info[s]] == x)) && (top_rod[disk_info[d]] <= x)) {
  //   count = rec(x-1, disk_info[x-1], r, d, count);
  // }
  //
  // if(s == d) {
  //   count = rec(x-1, disk_info[x-1], d, r, count);
  // } else {
  //   if(s == r) {
  //     count += (int(pow(2.0, x)) - 1);
  //   } else {
  //     count += int(pow(2.0, x-1));
  //   }
  // }
  // return count;
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

  // if(n == 1 && disk_info[1] == k) {
  //   result = 0;
  // } else {
  //   result = rec(n, disk_info[n], k, 6-disk_info[n]-k, result);
  // }
  result = rec(n, disk_info[n], k, 6-disk_info[n]-k, result);

  // // disk_info 확인
  // for(i = 1; i < 4; i++) {
  //   cout << "disk" << i << " :" << disk_info[i] << endl;
  // }
  //
  // // top_rod 확인
  // cout << "r1 : " << top_rod[1] << endl;
  // cout << "r2 : " << top_rod[2] << endl;
  // cout << "r3 : " << top_rod[3] << endl;

  printf("%d\n", result);


}
