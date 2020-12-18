#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, d, m;
vector<int> tasks;

bool is_valid(int k) {
  int i = 0;
  int count;

  for(int day = 1; day <= n && i < m; day++) {
    for(count = 0; count < k && i < m; count++) {
      if(day > tasks[i]+d){
        return false;
      }

      if(day >= tasks[i])
        i += 1;
      else
        break;

    }
  }

  return true;
}

int main() {
  int i, l, r, mid;
  scanf("%d %d %d", &n, &d, &m);

  priority_queue<int, vector<int> > pq;
  for(i = 0; i < m; i++) {
    int s;
    scanf("%d", &s);
    pq.push((-1)*s);
  }
  for(i = 0; i < m; i++) {
    tasks.push_back((-1)*pq.top());
    pq.pop();
  }

  l = 0; 
  r = m+1;
  while(l+1 < r) {
    mid = (l+r)/2;

    if(is_valid(mid)) {
      r = mid;
    }
      
    else {
      l = mid;
    }
  }

  printf("%d\n", r);

  return 0;
}