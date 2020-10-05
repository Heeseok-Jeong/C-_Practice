#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int size_f, size_g, i, j, l, r, p, q, result = 0;
  // map<int, int> info;
  // map<int, int>::iterator it, it2;
  vector<int> v_temp1, v_temp2;
  vector<vector<int> > f, g, info, vv_temp;
  vector<vector<int> >::iterator it;

  scanf("%d", &size_f);
  for(i = 0; i < size_f; i++) {
    scanf("%d %d", &l, &r);
    vv_temp.push_back(l);
    vv_temp.push_back(r);
    f.push_back(vv_temp));
  }
  scanf("%d", &size_g);
  for(i = 0; i < size_g; i++) {
    scanf("%d %d", &l, &r);
    vv_temp.push_back(l);
    vv_temp.push_back(r);
    g.push_back(vv_temp));
  }
  scanf("%d %d", &p, &q);

  i = 0;
  j = 0;
  if(f[i][0] < g[j][0]) {
    info.push_back(f[i]);
    if(i < num_f) {
      i++;
    }
    while((i < num_f) || (j < num_g)) {
      v_temp1 = f[i];
      v_temp2 = g[j];
      if(v_temp1[0] < v_temp2[0]) {
        if(v_temp1[1] > v_temp2[1]) {

        }
      }
    }
  } else {
    info.push_back(g[i++]);
  }


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

  // scanf("%d", &size_f);
  // for(i = 0; i < size_f; i++) {
  //   scanf("%d %d", &l, &r);
  //   info.insert(pair<int, int>(l, r));
  // }
  // scanf("%d", &size_g);
  // for(i = 0; i < size_g; i++) {
  //   scanf("%d %d", &l, &r);
  //   if(!(info.find(l) == info.end())) {
  //     if(info[l] < r) {
  //       info[l] = r;
  //     }
  //     continue;
  //   }
  //   info.insert(pair<int, int>(l, r));
  // }
  // scanf("%d %d", &p, &q);
  //
  // // // 입력값 확인
  // // cout << endl;
  // // for(it = info.begin(); it != info.end(); it++) {
  // //   cout << it->first << " " << it->second << endl;
  // // }
  // // cout << "p : " << p << ", q : " << q << endl;
  //
  // it = info.begin();
  // // it2 = info.rbegin();
  // if((q >= it->first) && (p <= info.rbegin()->first)) {
  //   if(info.size() == 1) {
  //     if(q >= it->first) {
  //       result += (q - it->first + 1) * it->second;
  //     }
  //   }
  //   else {
  //     for(; (p >= it->first) && (it != info.end()); it++) {}
  //     // cout << "it->first : " << it->first << endl;
  //
  //     if(it != info.begin()) {
  //       it2 = it;
  //       it2--;
  //       // cout << "it->first - p : " << it->first - p << ", it2->second : " << it2->second << endl;
  //       result += (it->first - p) * it2->second;
  //     }
  //     // cout << "a : " << result << endl;
  //     if(it != info.end()) {
  //       it++;
  //       it2 = it;
  //       it2--;
  //     }
  //
  //     for(; q >= it->first; it++, it2++) {
  //       if(it == info.end()) {
  //         it--;
  //         result += (q - it->first + 1) * it->second;
  //         // cout << "r3 : " << result << endl;
  //         break;
  //       }
  //       // cout << "it->first : " << it->first << endl;
  //       // cout << "it->first - it2->first : " << it->first - it2->first << ", it2->second : " << it2->second << endl;
  //       result += (it->first - it2->first) * it2->second;
  //       // cout << "r : " << result << endl;
  //     }
  //
  //     if(it->first > q) {
  //       result += (q - it2->first + 1) * it2->second;
  //       // cout << "r2 : " << result << endl;
  //     }
  //   }
  //
  // }

  printf("%d\n", result);
}
