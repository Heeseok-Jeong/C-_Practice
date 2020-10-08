#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  int n, k, x, i, j, l, r, diff, min, temp = 0;
  int l_diff, r_diff, l_target, r_target, count = 0;
  vector<int> poles, selected;
  vector<int>::iterator it, it2;

  scanf("%d %d", &n, &k);
  for(i = 0; i < n; i++) {
    scanf("%d", &x);
    poles.push_back(x);
  }
  sort(poles.begin(), poles.end());

  // cout << endl;
  // for(it=poles.begin(); it != poles.end(); it++) {
  //   cout << *it << endl;
  // }
  // cout << endl;

  // cout << "diff : " << diff << endl;
  if(n == k) {
    selected = poles;
  }
  else {
    selected.push_back(poles[0]);
    selected.push_back(poles[n-1]);
    l = 0;
    r = n-1;
    count = k-2;
    diff = (poles[r]-poles[l]) / (k-1);
    // cout << "min : " << min << ", diff : " << diff << endl;
    while(count > 0) {
      // cout << "count : " << count << endl;
      l_target = poles[l] + diff;
      r_target = poles[r] - diff;
      l_diff = diff;
      r_diff = diff;
      i = l;
      i++;
      temp = abs(l_target - poles[i]);
      while(temp < l_diff) {
        l_diff = temp;
        i++;
        temp = abs(l_target - poles[i]);
      }
      i--;

      j = r;
      j--;
      temp = abs(r_target - poles[j]);
      while(temp < r_diff) {
        r_diff = temp;
        j--;
        temp = abs(r_target - poles[j]);
      }
      j++;

      // cout << "l : " << l << ", i : " << i << ", l_diff : " << l_diff << endl;
      // cout << "r : " << r << ", j : " << j <<", r_diff : " << r_diff << endl;
      if(l_diff < r_diff) {
        selected.push_back(poles[i]);
        l = i;
      }
      else {
        selected.push_back(poles[j]);
        r = j;
      }
      // cout << min << endl;
      count--;
    }
    sort(selected.begin(), selected.end());
  }


  cout << endl << "selected" << endl;
  for(it=selected.begin(); it != selected.end(); it++) {
    cout << *it << endl;
  }
  cout << endl;

  it = selected.begin();
  it2 = it++;
  min = poles[n-1]-poles[0];
  for(; it != selected.end(); it++, it2++) {
    if(min > *it-*it2) {
      min = *it-*it2;
      // cout << "min : " << min << endl;
    }
  }
  // cout << endl;
  printf("%d\n", min);
  return 0;
}
