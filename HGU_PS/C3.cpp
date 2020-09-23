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

  // cout << start << " : ";
  while(!q.empty()) {
    int temp = q.front();
    q.pop();
    // cout << temp << " ";
    for(it = info[temp].begin(); it != info[temp].end(); it++) {
      if(!visited[*it]) {
        q.push(*it);
        visited[*it] = true;
        dis[*it] = dis[temp]+1;
      }
    }
  }
  // cout << endl;
}

int main() {
  int p, q, r, n, m, i, a, b, result = 0;
  vector< vector<int> > info;
  vector<int> A_dis, B_dis, N_dis;

  //입력
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

  //BFS
  BFS(1, n, info, A_dis);
  BFS(2, n, info, B_dis);
  BFS(n, n, info, N_dis);


  // 최저 사용량 계산
  result = p*A_dis[1] + q*B_dis[1] + r*N_dis[1];
  for(i = 2; i < n+1; i++) {
    a = p*A_dis[i] + q*B_dis[i] + r*N_dis[i];
    if(result > a) {
      result = a;
    }
  }
  printf("%d\n", result);

  // cout << "A_dis : ";
  // for(vector<int>::iterator it = A_dis.begin(); it != A_dis.end(); it++) {
  //   cout << *it << " ";
  // }
  // cout << endl;
  //
  // cout << "B_dis : ";
  // for(vector<int>::iterator it = B_dis.begin(); it != B_dis.end(); it++) {
  //   cout << *it << " ";
  // }
  // cout << endl;
  //
  // cout << "N_dis : ";
  // for(vector<int>::iterator it = N_dis.begin(); it != N_dis.end(); it++) {
  //   cout << *it << " ";
  // }
  // cout << endl;



  // // 입력 체크
  // for(i = 0; i < n+1; i++) {
  //   cout << i << " : ";
  //   for(vector<int>::iterator it = info[i].begin(); it != info[i].end(); it++) {
  //     cout << *it << " ";
  //   }
  //   cout << endl;
  // }
}
