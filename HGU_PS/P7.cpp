#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

long long n, i, j, len;
long long memo_sum[501][501];
long long initial_sum[501];
long long cable_len[501];

long long get_min(long long a, long long b) {
  if(a < b) return a;
  else return b;
}

int main() {
  scanf("%lld", &n);
  for(i = 1; i < n+1; i++) {
    scanf("%lld", &cable_len[i]);
    initial_sum[i] = initial_sum[i-1] + cable_len[i];
  }

  for(long long dist = 1; dist < n; dist++) {
    for(i = 1; i + dist < n+1; i++) {
      j = i + dist;
      memo_sum[i][j] = INT_MAX;
      for(long long mid = i; mid < j; mid++) {
        memo_sum[i][j] = get_min(memo_sum[i][j], memo_sum[i][mid] + memo_sum[mid+1][j] + initial_sum[j] - initial_sum[i-1]);
      }
    }
  }

  printf("%lld\n", memo_sum[i][n]);

  return 0;
}
