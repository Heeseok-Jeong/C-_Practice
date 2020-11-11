#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

struct cmp {
  bool operator()(pair<double, double> p1, pair<double, double> p2) {
    return p1.first > p2.first;
  }
};

int main() {
  int n, d, i, j;
  double left_x, right_x;
  scanf("%d %d", &n, &d);
  priority_queue<pair<double, double>, vector<pair<double, double> >, cmp> x_range_pq;
  for(i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    if(d < y)
      continue;
    left_x = double(x - sqrt(pow(d, 2)-pow(y, 2)));
    right_x = double(x + sqrt(pow(d, 2)-pow(y, 2)));
    x_range_pq.push(make_pair(left_x, right_x));
  }

  vector<pair<double, double> > x_range_v;
  while(!x_range_pq.empty()) {
    x_range_v.push_back(x_range_pq.top());
    x_range_pq.pop();
  }

  int wells_count = 0;
  i = 0;
  while(i < n) {
    for(j = i+1; j < n; j++) {
      if(x_range_v[i].second > x_range_v[j].second) {
        i = j-1;
        break;
      }
      else if(x_range_v[i].second < x_range_v[j].first){
        wells_count++;
        i = j-1;
        break;
      }
    }
    i++;
  }
  wells_count++;

  printf("%d\n", wells_count);

  return 0;
}
