#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

vector<int> parent_table, heights;

int find(int x) {
  if(parent_table[x] == x)
    return x;
  else
    return parent_table[x] = find(parent_table[x]);
}

void merge(int source, int target) {
  int root_s = find(source);
  int root_t = find(target);
  if(heights[root_s] < heights[root_t]) {
    parent_table[root_s] = root_t;
  }
  else if(heights[root_s] > heights[root_t]) {
    parent_table[root_t] = root_s;
  }
  else {
    parent_table[root_s] = root_t;
    heights[root_t]++;
  }
}

int main() {
  int n, i, j;
  scanf("%d", &n);
  vector<pair<long long, long long> > buildings;
  for(i = 0; i < n; i++) {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    buildings.push_back(make_pair(x, y));
  }

  heights.assign(n, 0);
  parent_table.assign(n, 0);
  for(i = 0; i < n; i++) {
    parent_table[i] = i;
  }

  for(i = 0; i < n-1; i++) {
    for(j = i+1; j < n; j++) {
      if(sqrt(pow(buildings[i].first - buildings[j].first, 2) + pow(buildings[i].second - buildings[j].second, 2)) <= 5) {
        merge(j, i);
      }
    }
  }

  map<int, int> no_together_group;
  for(i = 0; i < n; i++) {
    no_together_group[find(i)] = 0;
  }

  for(i = 0; i < n; i++) {
    no_together_group[find(i)]++;
    // cout << find(i) << ", ";
  }

  int max_num = 0;
  for(auto it = no_together_group.begin(); it != no_together_group.end(); it++) {
    if(it->second % 2 == 0)
      max_num += it->second/2;
    else
      max_num += it->second/2 + 1;
  }

  cout << n-max_num << endl;

  return 0;
}
