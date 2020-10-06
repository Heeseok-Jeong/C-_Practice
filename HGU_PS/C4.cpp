#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

vector<int> stack, diff, poles;
map<int, bool> visited;
int k, min;

int dfs(int x, int depth) {
  int i, temp = 0;
  if(depth == k) {
    while()
    visited[]
  }
  else {

  }

  return min;
}

int main() {
  int n, i, x = 0;
  min = 0;
  scanf("%d %d", &n, &k);
  for(i = 0; i < n; i++) {
    scanf("%d", &x);
    stack.push_back(x);
    poles.push_back(x);
    visited.insert(pair<int, bool>(x, false));
  }

  x = stack.pop_back();
  visited[x] = true;
  min = dfs(x, 0, min);
  printf("%d\n", min);

  return 0;
}
