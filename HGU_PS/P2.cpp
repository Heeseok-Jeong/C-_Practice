#include <iostream>
#include <map>
using namespace std;

long long max(long long a, long long b) {
  if(a > b) return a;
  else return b;
}

int main() {
  int n, k, i, g = 0;
  long long x, result, temp = 0;
  map<long long, int> m;
  map<long long, int>::iterator it1, it2;

  scanf("%d %d", &n, &k);

  for(i = 0; i < n; i++) {
    scanf("%d %lld", &g, &x);
    m[x] = g;
  }

  // for (it1 = m.begin(); it1 != m.end(); it1++)
  //       cout << "key : " << it1->first << " value : " << it1->second << endl;

  i = 0;
  for(it1 = m.begin(); it1 != m.end(); it1++) {
    // cout << "a : " << result << ", b : " << temp << endl;
    result = max(result, temp);
    if(i == n-1) {
      result = max(result, it1->second);
    } else {
      temp = 0;
      for(it2 = it1; it2 != m.end(); it2++) {
        if(it2->first <= it1->first+2*k) {
          temp += it2->second;
        } else {
          break;
        }
      }
    }
    i++;
    // cout << "temp : " << temp << endl;
  }

  printf("%lld\n", result);

  return 0;
}
