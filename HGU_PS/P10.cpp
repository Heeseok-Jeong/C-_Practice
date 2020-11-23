#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n;
vector<int> root_table, heights, routes[451];
vector<bool> visited;
set<vector<int> > cycles;

int find(int x) {
  if(x == root_table[x])
    return x;
  else
    return root_table[x] = find(root_table[x]);
}

void merge(int root_s, int root_t) {
  if(heights[root_t] < heights[root_s])
    root_table[root_t] = root_s;
  else if(heights[root_t] > heights[root_s])
    root_table[root_s] = root_t;
  else {
    if(root_s < root_s) {
      int temp = root_s;
      root_s = root_t;
      root_t = temp;
    }
    root_table[root_s] = root_t;
    heights[root_t]++;
  }
}

bool check_same_root(int source, int target) {
  int root_s = find(source);
  int root_t = find(target);

  if(root_s != root_t) {
    merge(root_s, root_t);
    return false;
  }
  else
    return true;
}

void check_cycle(int source, int target, vector<int> cycle) {
  cycle.push_back(source);
  // cout << "source : " << source << ", target : " << target << endl;
  visited[source] = true;

  if(source == target) {
    // cout << "yes!\n";
    sort(cycle.begin(), cycle.end());
    cycles.insert(cycle);
    return;
  }

  for(int i = 1; i < n+1; i++) {
    if(routes[source][i] && !visited[i]) {
      check_cycle(i, target, cycle);
      visited[i] = false;
    }
  }
  // cout << "out\n";
}

int main() {
  int b, i, j;
  scanf("%d %d", &n, &b);

  vector<int> weights;
  weights.assign(n+1, 0);
  int max_sum = 0;
  for(i = 1; i < n+1; i++) {
    int weight;
    scanf("%d", &weight);
    weights[i] = weight;

    if(max_sum < weight)
      max_sum = weight;
  }

  root_table.assign(n+1, 0);
  for(i = 1; i < n+1; i++) {
    root_table[i] = i;
  }

  for(i = 0; i < n+1; i++) {
    routes[i].assign(n+1, 0);
  }

  heights.assign(n+1, 1);

  for(i = 0; i < b; i++) {
    int target, source;
    scanf("%d %d", &source, &target);

    if(check_same_root(source, target)) {
      // cout << "cycle!\n";
      visited.assign(n+1, false);
      vector<int> cycle;
      check_cycle(source, target, cycle);
      // cout << "cycle out\n";
    }

    routes[source][target] = 1;
    routes[target][source] = 1;

    int weight = weights[source] + weights[target];
    if(max_sum < weight)
      max_sum = weight;
    // // cout << "root_table" << endl;
    // for(int j = 0; j < n+1; j++)
    //   cout << root_table[j] << ", ";
    // cout << endl;
  }
  // cout << "all out!\n";

  // cout << "routes" << endl;
  // for(i = 1; i < n+1; i++) {
  //   for(int j = 1; j < n+1; j++) {
  //     cout << routes[i][j] << ", ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;


  for(auto cycle : cycles) {
    for(auto node : cycle) {
      cout << node << ", ";
    }
    cout << endl;
    int sum = 0;
    int cycle_size = cycle.size();
    // cout << "cycle_size : " << cycle_size << endl;
    if(cycle_size <= 3) {
      for(i = 0; i < cycle_size; i++) {
        sum += weights[cycle[i]];
      }
    }
    else {
      bool is_all_connected = true;
      for(i = 0; i < cycle_size-1 && is_all_connected; i++) {
        for(int j = i+1; j < cycle_size; j++) {
          if(!routes[cycle[i]][cycle[j]]) {
            is_all_connected = false;
            break;
          }
        }
      }

      if(is_all_connected) {
        for(i = 0; i < cycle_size; i++) {
          sum += weights[cycle[i]];
        }
      }
    }
    // cout << "sum : " << sum << endl;

    if(max_sum < sum)
      max_sum = sum;
  }

  cout << max_sum << endl;
  return 0;
}
