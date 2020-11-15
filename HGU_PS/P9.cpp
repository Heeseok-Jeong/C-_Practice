#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  long long n, t, i, p, spd;
  scanf("%lld %lld", &n, &t);
  vector<pair<long long, long long> > people_info;
  for(i = 0; i < n; i++) {
    scanf("%lld %lld", &p, &spd);
    people_info.push_back(make_pair(p, spd));
  }
  sort(people_info.begin(), people_info.end());

  vector<long long> groups;
  for(i = 0; i < n; i++) {
    groups.push_back(people_info[i].first + t*people_info[i].second);
  }

  bool is_changed = true;
  while(is_changed) {
    long long groups_size = groups.size();
    if(groups_size == 1)
      break;

    is_changed = false;
    vector<long long> temp_group;
    if(groups[0] >= groups[1]) {
      temp_group.push_back(groups[1]);
      is_changed = true;
    }
    else {
      temp_group.push_back(groups[0]);
    }

    for(i = 1; i < groups_size-1; i++) {
      if(*temp_group.rbegin() != groups[i]) {
        if(groups[i] >= groups[i+1]) {
          temp_group.push_back(groups[i+1]);
          if(!is_changed)
            is_changed = true;
        }
        else {
          temp_group.push_back(groups[i]);
        }
      }
    }
    if(*temp_group.rbegin() < *groups.rbegin())
      temp_group.push_back(*groups.rbegin());

    groups = temp_group;
  }

  printf("%lu\n", groups.size());

  return 0;
}
