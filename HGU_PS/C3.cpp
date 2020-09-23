#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int start, int n, vector< vector<int> >& info, vector<int>& dis) {
  queue<int> q;
  vector<int>::iterator it;
  vector<bool> visited;
  visited.resize(n+1, false);
  q.push(start);
  visited[start] = true;

  while(!q.empty()) {
    int temp = q.front();
    q.pop();
    for(it = info[temp].begin(); it != info[temp].end(); it++) {
      if(!visited[*it]) {
        q.push(*it);
        visited[*it] = true;
        dis[*it] = dis[temp]+1;
      }
    }
  }
}

int main() {
  int p, q, r, n, m, i, a, b, result = 0;
  vector< vector<int> > info;
  vector<int> A_dis, B_dis, N_dis;

  cin >> p >> q >> r >> n >> m;
  info.resize(n+1);
  A_dis.resize(n+1, 0);
  B_dis.resize(n+1, 0);
  N_dis.resize(n+1, 0);
  for(i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    info[a].push_back(b);
    info[b].push_back(a);
  }

  BFS(1, n, info, A_dis);
  BFS(2, n, info, B_dis);
  BFS(n, n, info, N_dis);


  result = p*A_dis[1] + q*B_dis[1] + r*N_dis[1];
  for(i = 2; i < n+1; i++) {
    a = p*A_dis[i] + q*B_dis[i] + r*N_dis[i];
    if(result > a) {
      result = a;
    }
  }
  printf("%d\n", result);
}
