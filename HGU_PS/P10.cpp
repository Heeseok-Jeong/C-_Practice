#include <iostream>
#include <vector>

using namespace std;

vector<int> root_table, heights;

int find(x) {
  if(x == root_table[x])
    return x;
  else
    return root_table[x] = find(x);
}

void merge(int target, int source) {
  int root_t = find(target);
  int root_s = find(source);

  if(heights[root_t] < heights[root_s])
    root_table[root_t] = root_s;
  else if(heights[root_t] > heights[root_s])
    root_table[root_s] = root_t;
  else {
    root_table[root_s] = root_t;
    heights[root_t]++;
  }
}

int main() {
  int n, b, i, j;
  scanf("%d %d", &n, &b);

  vector<int> weights, route[n+1];
  weights.assign(n+1, 0);
  for(i = 1; i < n+1; i++) {
    int weight;
    scanf("%d", &weight);
    weights[i] = weight;
  }

  root_table.assign(n+1, 0);
  for(i = 1; i < n+1; i++) {
    root_table[i] = i;
  }

  for(i = 0; i < n+1; i++ {
    route[i].assign(n+1, 0);
  }

  heights.assign(n+1, 1);

  for(i = 0; i < b; i++) {
    int a, b;
    scanf("%d %d", &a, &b);

    merge(target, source);

    route[a][b] = 1;
    route[b][a] = 1;
  }





  return 0;
}
