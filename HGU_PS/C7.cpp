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

void update_parent_table(int small, int large) {
  int small_root = find_root(small);
  int large_root = find_root(large);

  if(large_root != small_root) {
    if(tree_height[large_root] > tree_height[small_root]) {
      int temp = small_root;
      small_root = large_root;
      large_root = temp;
    }
    parent_table[large_root] = small_root;
    if(tree_height[large_root] == tree_height[small_root])
      tree_height[large_root] += 1;
  }
}
//지금 방법 타임컴플렉시티 분석하고 알고리즘 적으로 줄이거나 최적화로 줄여야 함.

void find_cycle_elements_count(int depth, int x, int target) {
  if(x == target) {
    cycle_elements_count_v.push_back(depth);
    return;
  }

  int i;
  for(i = 1; i < n+1; i++) {
    if(route_table[x][i] == 1 && !visited[i]) {
      visited[i] = true;
      find_cycle_elements_count(depth+1, i, target);
      visited[i] = false;
    }
  }
}

int main() {
  int m, i, j;
  scanf("%d", &n);
  scanf("%d", &m);

  parent_table.resize(n+1);
  for(i =1; i < n+1; i++) {
      parent_table[i] = i;
  }

  tree_height.assign(n+1, 1);

  for(i = 0; i < n+1; i++) {
    vector<int> route(n+1, 0);
    route_table.push_back(route);
  }

  bool is_done = false;
  for(i = 0; i < m && !is_done; i++) {
    int small, large;
    scanf("%d %d", &small, &large);
    if(small > large) {
      int temp = small;
      small = large;
      large = temp;
    }

    // update_parent_table(small, large);

    if(find_root(small) != find_root(large)) {
      update_parent_table(small, large);
      // cout << "p_t\n";
      // for(j = 1; j < n+1; j++)
      //   cout << parent_table[j] << ", ";
      // cout << endl;
    }

    else {
      int depth = 1;
      visited.assign(n+1, false);
      visited[large] = true;
      cycle_elements_count_v.clear();
      find_cycle_elements_count(depth, large, small);

      for(auto count : cycle_elements_count_v) {
        // cout << "count : " << count << endl;
        if(count%2 == 1) {
          is_done = true;
          break;
        }
      }
    }

    route_table[small][large] = 1;
    route_table[large][small] = 1;
  }

  printf("%d\n", i);

  return 0;
}
