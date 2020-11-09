#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cmp {
  bool operator()(int n1, int n2) {
    return n1 > n2;
  }
};

int main() {
  int n, d, m, i, j, k;
  scanf("%d %d %d", &n, &d, &m);
  priority_queue<int, vector<int>, cmp> pq;
  priority_queue<int, vector<int>, cmp> temp_pq;
  for(i = 0; i < m; i++) {
    int s;
    scanf("%d", &s);
    s += d;
    pq.push(s);
  }

  for(k = 1; k < n+1 && m/k > n; k++) {}
  cout << "init_k : " << k << endl;

  for(; k < n; k++) {
    cout << endl;
    cout << "k : " << k << endl;
    temp_pq = pq;
    int day = 1;
    int count = k;
    bool is_done = true;
    while(!temp_pq.empty()) {
      cout << "day : " << day << endl;
      int x = temp_pq.top();
      temp_pq.pop();
      count--;
      cout << "x : "<< x << endl;
      if(x < day) {
        cout << "x < day" << endl;
        is_done = false;
        break;
      }

      if(count == 0) {
        count = k;
        day++;
      }
      else {
        count--;
      }
    }

    if(is_done) {
      cout << "success!\n";
      break;
    }
  }

  printf("%d\n", k);

  return 0;
}
