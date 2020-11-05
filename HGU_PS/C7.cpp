#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > route_table;
vector<int> parent_table, tree_height, cycle_elements_count_v;
vector<bool> visited;
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

bool check_odd_cycle(int depth, int x, int target) {
  if(x == target) {
    if(depth%2 == 1)
      return true;
    else
      return false;
  }

  for(int i = 1; i < n+1; i++) {
    if(route_table[x][i] == 1 && !visited[i]) {
      visited[i] = true;
      if(check_odd_cycle(depth+1, i, target))
        return true;
      else
        return false;
      // visited[i] = false;
    }
  }
  return false;
}

int main() {
  int m, i;
  scanf("%d", &n);
  scanf("%d", &m);

  if(n == 1)
    printf("0");
  else if(n == 2) {
    for(i = 0; i < m; i++) {
      int small, large;
      scanf("%d %d", &small, &large);
      if(small > large) {
        int temp = small;
        small = large;
        large = temp;
      }
      if(small == 1 && large == 2) {
        printf("%d\n", i+1);
        break;
      }
    }
  }
  else {
    tree_height.assign(n+1, 1);
    parent_table.resize(n+1);
    for(i =1; i < n+1; i++) {
        parent_table[i] = i;
    }
    for(i = 0; i < n+1; i++) {
      vector<int> route(n+1, 0);
      route_table.push_back(route);
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
        int depth = 1;
        visited.assign(n+1, false);
        visited[large] = true;
        cycle_elements_count_v.clear();
        if(check_odd_cycle(depth, large, small))
          break;
      }

      route_table[small][large] = 1;
      route_table[large][small] = 1;
    }

    printf("%d\n", i+1);
  }
  return 0;
}
