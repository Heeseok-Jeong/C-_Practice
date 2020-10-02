#include <iostream>
#include <map>
using namespace std;

int main() {
  int size_f, size_g, i, l, r, p, q, result = 0;
  map<int, int> info;
  map<int, int>::iterator it, it2;

  scanf("%d", &size_f);
  for(i = 0; i < size_f; i++) {
    scanf("%d %d", &l, &r);
    info.insert(pair<int, int>(l, r));
  }
  scanf("%d", &size_g);
  for(i = 0; i < size_g; i++) {
    scanf("%d %d", &l, &r);
    if(!(info.find(l) == info.end())) {
      if(info[l] < r) {
        info[l] = r;
      }
      continue;
    }
    info.insert(pair<int, int>(l, r));
  }
  scanf("%d %d", &p, &q);

  // // 입력값 확인
  // cout << endl;
  // for(it = info.begin(); it != info.end(); it++) {
  //   cout << it->first << " " << it->second << endl;
  // }
  // cout << "p : " << p << ", q : " << q << endl;

  it = info.begin();
  // it2 = info.rbegin();
  if((q >= it->first) && (p <= info.rbegin()->first)) {
    if(info.size() == 1) {
      if(q >= it->first) {
        result += (q - it->first + 1) * it->second;
      }
    }
    else {
      for(; (p >= it->first) && (it != info.end()); it++) {}
      // cout << "it->first : " << it->first << endl;

      if(it != info.begin()) {
        it2 = it;
        it2--;
        // cout << "it->first - p : " << it->first - p << ", it2->second : " << it2->second << endl;
        result += (it->first - p) * it2->second;
      }
      // cout << "a : " << result << endl;
      if(it != info.end()) {
        it++;
        it2 = it;
        it2--;
      }

      for(; q >= it->first; it++, it2++) {
        if(it == info.end()) {
          it--;
          result += (q - it->first + 1) * it->second;
          // cout << "r3 : " << result << endl;
          break;
        }
        // cout << "it->first : " << it->first << endl;
        // cout << "it->first - it2->first : " << it->first - it2->first << ", it2->second : " << it2->second << endl;
        result += (it->first - it2->first) * it2->second;
        // cout << "r : " << result << endl;
      }

      if(it->first > q) {
        result += (q - it2->first + 1) * it2->second;
        // cout << "r2 : " << result << endl;
      }
    }

  }

  printf("%d\n", result);
}
