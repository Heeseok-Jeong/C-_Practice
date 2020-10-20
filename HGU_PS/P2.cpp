#include <iostream>
#include <queue>

using namespace std;

struct cmp {
  bool operator()(pair<long long, long long> p1, pair<long long, long long> p2) {
    if(p1.first != p2.first)
      return p1.first > p2.first;
    else
      return p1.second < p2.second;
  }
};

int main() {
  long long n, k, i, available_num, max_available_num = 0;
  priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, cmp> info;
  scanf("%lld %lld", &n, &k);

  for(i = 0; i < n; i++) {
    long long x, g;
    scanf("%lld %lld", &g, &x);
    info.push(make_pair(x-k, g));
    info.push(make_pair(x+k, g-2*g));

    if(max_available_num < x && k == 0)
      max_available_num = x;
  }

  while(!info.empty()) {
    pair<long long, long long> temp = info.top();
    available_num += temp.second;
    info.pop();
    if(max_available_num < available_num)
      max_available_num = available_num;
  }

  printf("%lld\n", max_available_num);
  return 0;
}
