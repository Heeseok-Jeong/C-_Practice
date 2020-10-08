#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n, k, x, i, left, right, predict, result = 0;
  int latest_amp, count_amp, distance, smallest_distance = 0;
  int poles[100000];

  scanf("%d %d", &n, &k);
  for(i = 0; i < n; i++) {
    scanf("%d", &x);
    poles[i] = x;
  }
  sort(poles, poles+n);

  left = 1;
  right = poles[n-1] - poles[0];
  while(left <= right) {
    predict = (left+right)/2;
    latest_amp = 0;
    count_amp = 1;
    distance = 0;
    smallest_distance = right;

    for(i = 1; i < n; i++) {
      distance = poles[i] - poles[latest_amp];
      if(predict <= distance) {
        if(smallest_distance > distance) {
          smallest_distance = distance;
        }
        latest_amp = i;
        count_amp++;
      }
    }

    if(count_amp >= k) {
      if(result < smallest_distance) {
        result = smallest_distance;
      }
      left = predict + 1;
    }
    else {
      right = predict - 1;
    }
  }
  printf("%d\n", result);
  return 0;
}
