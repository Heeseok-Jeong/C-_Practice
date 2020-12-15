#include <iostream>
#include <limits.h>

using namespace std;

int n, i, j, len;
int memo_sum[501][501];
int initial_sum[501];
int cable_len[501];

int get_min(int a, int b) {
  if(a < b) return a;
  else return b;
}

int main() {
  scanf("%d", &n);
  for(i = 1; i < n+1; i++) {
    scanf("%d", &cable_len[i]);
    initial_sum[i] = initial_sum[i-1] + cable_len[i];
  }

  for(int dist = 1; dist < n; dist++) {
    for(i = 1; i + dist < n+1; i++) {
      j = i + dist;
      memo_sum[i][j] = INT_MAX;
      for(int mid = i; mid < j; mid++) {
        memo_sum[i][j] = get_min(memo_sum[i][j], memo_sum[i][mid] + memo_sum[mid+1][j] + initial_sum[j] - initial_sum[i-1]);
      }
    }
  }

  printf("%d\n", memo_sum[1][n]);

  return 0;
}
