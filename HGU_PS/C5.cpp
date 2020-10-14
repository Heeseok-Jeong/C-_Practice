#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

struct Balloon {
  int x;
  int limit_r;
  double r;
};

int main() {
  int n, i = 0;
  vector<Balloon> balloons;

  scanf("%d", &n);

  for(i = 0; i < n; i++) {
    int x_i, limit_r_i;
    scanf("%d %d", &x_i, &limit_r_i);
    Balloon balloon_i;
    balloon_i.x = x_i;
    balloon_i.limit_r = limit_r_i;
    balloon_i.r = 0;
    balloons.push_back(balloon_i);
  }

  double left_x_i, r, min_r = 0;
  multimap<double, int, greater<double> > sorted_right;
  multimap<double, int, greater<double> >::iterator it_mm;
  balloons[0].r = balloons[0].limit_r;
  sorted_right.insert(pair<double, int>(balloons[0].x+balloons[0].r, 0));

  for(i = 1; i < n; i++) {
    min_r = balloons[i].limit_r;
    left_x_i = balloons[i].x - min_r;
    if(sorted_right.begin()->first > left_x_i) {
      for(it_mm = sorted_right.begin(); it_mm != sorted_right.end() && it_mm->first > left_x_i; it_mm++) {
        r = pow(balloons[i].x - balloons[it_mm->second].x, 2) / (4*balloons[it_mm->second].r);
        if(min_r > r)
          min_r = r;
      }
    }
    balloons[i].r = min_r;
    sorted_right.insert(pair<double, int>(balloons[i].x + balloons[i].r, i));
  }

  for(i = 0; i < n; i++) {
    printf("%.3lf\n", balloons[i].r);
  }

  return 0;
}
