#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

struct cmp {
  bool operator()(pair<long long, long long> p1, pair<long long, long long> p2) {
    if(p1.first == p2.first)
      return p1.second > p2.second;
    else
      return p1.first > p2.first;
  }
};

int main() {
  int n, i, j;
  scanf("%d", &n);
  vector<pair<long long, long long> > buildings;
  priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, cmp> pq;
  for(i = 0; i < n; i++) {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    pq.push(make_pair(x, y));
  }

  for(i = 0; i < n; i++) {
    buildings.push_back(pq.top());
    pq.pop();
  }

  // for(i = 0; i < n; i++) {
  //   cout << "i : " << i << ", " << buildings[i].first << ", " << buildings[i].second << endl;
  // }

  vector<int> group;
  vector<bool> visited;
  map<int, vector<int> > no_together_list;
  // vector<int> graph[50000];
  // for(i = 0; i < n; i++) {
  //   graph[i].assign(n, 0);
  // }

  for(i = 0; i < n-1; i++) {
    int count = 2;
    for(j = i+1; j < n && count != 0; j++) {
      if(buildings[j].first - buildings[i].first > 5)
        break;

      if(abs(buildings[j].second - buildings[i].second) > 5)
        continue;
      // if(buildings[i].first == buildings[j].first) {
      //   if(buildings[j].second - buildings[i].second <= 5) {
      //     no_together_list[i].push_back(j);
      //     count--;
      //   }
      // }
      // else if(sqrt(pow(buildings[i].first - buildings[j].first, 2) + pow(buildings[i].second - buildings[j].second, 2)) <= 5) {
      if(sqrt(pow(buildings[i].first - buildings[j].first, 2) + pow(buildings[i].second - buildings[j].second, 2)) <= 5) {
        // cout << "i : " << i << ", j : " << j << ", " << sqrt(pow(buildings[i].first - buildings[j].first, 2) + pow(buildings[i].second - buildings[j].second, 2)) << endl;
        no_together_list[i].push_back(j);
        // graph[i][j] = 1;
        // graph[j][i] = 1;
        count--;
      }
    }
  }

  // for(i = 0; i < n; i++) {
  //   for(j = 0; j < n; j++) {
  //     cout << graph[i][j] << ", ";
  //   }
  //   cout << endl;
  // }

  // for(auto it = no_together_list.begin(); it != no_together_list.end(); it++) {
  //   cout << "key : " << it->first << endl;
  //   for(auto x : it->second) {
  //     cout << x << ", ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  visited.assign(n, false);
  queue<int> que;
  int max_brand_count = 0;
  for(i = 0; i < n; i++){
    if(!visited[i]) {
      que.push(i);
      // cout << "start : " << i << endl;
      int brand = 1;
      int brand_1_count = 0;
      int brand_2_count = 0;
      while(!que.empty()) {
        int a = que.front();
        que.pop();
        if(visited[a])
          continue;
        visited[a] = true;
        // cout << a << ", ";

        if(brand == 1) {
          brand_1_count++;
          brand = 2;
        }
        else {
          brand_2_count++;
          brand = 1;
        }

        // for(int b = 0; b < n; b++) {
        //   if(graph[a][b] == 1 && a != b) {
        //     que.push(graph[a][b]);
        //   }
        // }

        if(no_together_list.find(a) != no_together_list.end()) {
          for(auto b : no_together_list[a]) {
            if(!visited[b]) {
              que.push(b);
            }
          }
        }
      }
      // cout << endl;
      // cout << "b1count : " << brand_1_count << endl;
      // cout << "b2count : " << brand_2_count << endl;
      if(brand_1_count < brand_2_count)
        max_brand_count += brand_2_count;
      else
        max_brand_count += brand_1_count;
    }
  }


  cout << n - max_brand_count << endl;

  return 0;
}
