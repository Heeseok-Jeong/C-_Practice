#include <iostream>
#include <map>
using namespace std;

int main() {
  long long temp, size_f, size_g, i, l, r, p, q = 0;
  long long result = 0;
  map<long long, long long> info, new_info;
  map<long long, long long>::iterator it, it2;

  scanf("%lld", &size_f);
  for(i = 0; i < size_f; i++) {
    scanf("%lld %lld", &l, &r);
    info.insert(pair<long long, long long>(l, r));
  }
  scanf("%lld", &size_g);
  for(i = 0; i < size_g; i++) {
    scanf("%lld %lld", &l, &r);
    if(!(info.find(l) == info.end())) {
      if(info[l] < r) {
        info[l] = r;
      }
      continue;
    }
    info.insert(pair<long long, long long>(l, r));
  }
  scanf("%lld %lld", &p, &q);

  for(temp = 0, it = info.begin(); it != info.end(); it++) {
    if(temp < it->second) {
      temp = it->second;
      new_info.insert(pair<long long, long long>(it->first, (it->second)));
    }
  }

  it = new_info.begin();
  if(q >= it->first) {
    if(p >= new_info.rbegin()->first) {
      result += (q-p+1)*new_info.rbegin()->second;
      result %= 10007;
    }
    else {
      for(; p > it->first; it++) {}

      if(it != new_info.begin()) {
        it2 = it;
        it2--;
        result += (it->first - p) * it2->second;
      }
      result %= 10007;

      it2 = it++;
      for(; (it != new_info.end()) && (it->first <= q); it++, it2++) {
        result += (it->first - it2->first) * it2->second;
        result %= 10007;
      }

      result += (q- it2->first + 1) * it2->second;
      result %= 10007;
    }
  }

  result %= 10007;
  printf("%lld\n", result);
}
