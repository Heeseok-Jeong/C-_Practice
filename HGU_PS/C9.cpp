#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> root_table, heights;

int find(int x) {
  if(x == root_table[x])
    return x;
  else
    return root_table[x] = find(root_table[x]);
}

void merge(int target, int source) {
  int root_t = find(target);
  int root_s = find(source);

  if(heights[root_t] < heights[root_s])
    root_table[root_t] = root_s;
  else if(heights[root_t] > heights[root_s])
    root_table[root_s] = root_t;
  else {
    if(root_s < root_t) {
      int temp = root_s;
      root_s = root_t;
      root_t = temp;
    }
    root_table[root_s] = root_t;
    heights[root_t]++;
  }
}

int main() {
  int n, i;
  scanf("%d", &n);
  heights.assign(n+1, 1);
  vector<pair<int, int> > p_v;
  for(i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    p_v.push_back(make_pair(x, y));
  }

  for(i = 0; i < n; i++) {
    root_table.push_back(i);
  }

  for(i = 0; i < n; i++) {
    for(int j = 0; j < i; j++) {
      if((p_v[i].first > p_v[j].first && p_v[i].second < p_v[j].second) \
        || (p_v[i].first < p_v[j].first && p_v[i].second > p_v[j].second))
      {
        merge(j, i);
      }
    }
  }

  set<int> disjoint_set;
  for(i = 0; i < n; i++) {
    find(i);
    disjoint_set.insert(root_table[i]);
  }

  cout << disjoint_set.size() << endl;

  return 0;
}
