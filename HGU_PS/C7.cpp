#include <iostream>
#include <vector>

using namespace std;

vector<int> route_list[10001];
vector<int> parent_table, tree_height, cycle_elements_count_v;
vector<bool> visited;
bool is_odd, is_cycle;
int n;

int find_root(int x) {
  if(parent_table[x] == x)
    return x;
  else
    return parent_table[x] = find_root(parent_table[x]);
}

void update_parent_table(int small_root, int large_root) {
  if(tree_height[large_root] > tree_height[small_root]) {
    int temp = small_root;
    small_root = large_root;
    large_root = temp;
  }

  parent_table[large_root] = small_root;
  if(tree_height[large_root] == tree_height[small_root])
    tree_height[large_root] += 1;
}

bool check_cycle(int small, int large) {
  int small_root = find_root(small);
  int large_root = find_root(large);

  if(large_root != small_root) {
    update_parent_table(small_root, large_root);
    return false;
  }
  else
    return true;
}

void check_odd_cycle(int depth, int x, int target) {
  if(x == target) {
    is_cycle = true;
    if(depth%2 == 1)
      is_odd = true;
    return;
  }

  for(auto it = route_list[x].begin(); it != route_list[x].end(); it++) {
    if(!visited[*it]) {
      visited[*it] = true;
      check_odd_cycle(depth+1, *it, target);
      if(is_cycle)
        return;
    }
  }
}

int main() {
  int m, i;
  scanf("%d", &n);
  scanf("%d", &m);

  tree_height.assign(n+1, 1);
  parent_table.resize(n+1);
  for(i = 1; i < n+1; i++) {
      parent_table[i] = i;
  }
  for(i = 0; i < n+1; i++) {

  }

  for(i = 0; i < m; i++) {
    int small, large;
    scanf("%d %d", &small, &large);
    if(small > large) {
      int temp = small;
      small = large;
      large = temp;
    }

    if(check_cycle(small, large)) {
      is_odd = false;
      is_cycle = false;
      int depth = 1;
      visited.assign(n+1, false);
      visited[large] = true;
      cycle_elements_count_v.clear();
      check_odd_cycle(depth, large, small);
      if(is_odd)
        break;
    }

    route_list[small].push_back(large);
    route_list[large].push_back(small);
  }

  printf("%d\n", i+1);
  return 0;
}
