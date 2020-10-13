#include <iostream>
#include <math.h>

using namespace std;

struct balloon {
  int x;
  int limit_r;
  double r;
};

const int N_MAX = 10^5;
const int X_MAX = 10^9;

double compute_r(balloon b_pre, balloon b_i) {
  double dist, diff, r = 0;
  int limit_dist = b_pre.r + b_i.limit_r;
  // cout << "limit_dist : " << limit_dist << endl;

  // dist = sqrt(pow(b_pre.x - b_i.x, 2) + pow(b_pre.r - b_i.limit_r, 2));
  dist = sqrt((b_pre.x - b_i.x)*(b_pre.x - b_i.x) + (b_pre.r - b_i.limit_r)*(b_pre.r - b_i.limit_r));
  diff = limit_dist - dist;
  // printf("dist : %lf, diff : %lf\n", dist, diff);
  dist = round(dist * double(10^5));

  if(diff > 0)
    // r = (pow(b_pre.x, 2) - 2*b_pre.x*b_i.x + pow(b_i.x, 2)) / (4*b_pre.r);
    r = (b_pre.x*b_pre.x - 2*b_pre.x*b_i.x + b_i.x*b_i.x) / (4*b_pre.r);
  else
    r = b_i.limit_r;
  // printf("r : %lf\n", r);
  return r;
}

int main() {
  int n, i = 0;
  balloon balloons[N_MAX];
  for(i = 0; i < N_MAX; i++) {
    balloons[i].x = 0;
    balloons[i].r = 0;
    balloons[i].limit_r = 0;
  }

  scanf("%d", &n);

  for(i = 0; i < n; i++) {
    int x_i, max_r_i;
    scanf("%d %d", &x_i, &max_r_i);
    balloons[i].x = x_i;
    balloons[i].limit_r = max_r_i;
  }


  balloons[0].r = balloons[0].limit_r;

  for(i = 1; i < n; i++) {
    double min_r = balloons[i].limit_r;
    // printf("min_r : %lf\n", min_r);
    for(int j = 0; j < i; j++) {
      // cout << "pre : " << j << ", i : " << i << endl;
      // cout << "pre_x : " << balloons[j].x << ", pre_r : " << balloons[j].r << endl;
      // cout << "i_x : " << balloons[i].x << ", i_r : " << balloons[i].r << endl;
      double r = compute_r(balloons[j], balloons[i]);
      if(min_r > r)
        min_r = r;
      // printf("r : %lf\n", min_r);
    }
    balloons[i].r = min_r;
  }

  // 출력
  // cout << endl;
  for(i = 0; i < n; i++) {
    printf("%.3lf\n", balloons[i].r);
  }

  return 0;
}
