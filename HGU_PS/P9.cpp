#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long n, t, i, p, speed;
  scanf("%lld %lld", &n, &t);
  vector<pair<long long, long long> > people_info;
  for(i = 0; i < n; i++) {
    scanf("%lld %lld", &p, &speed);
    people_info.push_back(make_pair(p, speed));
  }

  vector<long long> group_speed;
  for(i = 0; i < n; i++) {
    group_speed.push_back(people_info[i].first + t*people_info[i].second);
  }

  bool is_changed = true;
  while(is_changed) {
    long long group_speed_size = group_speed.size();
    if(group_speed_size == 1)
      break;

    is_changed = false;
    vector<long long> temp_group_size;
    if(group_speed[0] >= group_speed[1]) {
      temp_group_size.push_back(group_speed[1]);
      is_changed = true;
    }
    else {
      temp_group_size.push_back(group_speed[0]);
    }

    for(i = 1; i < group_speed_size-1; i++) {
      if(*temp_group_size.rbegin() != group_speed[i]) {
        if(group_speed[i] >= group_speed[i+1]) {
          temp_group_size.push_back(group_speed[i+1]);
          if(!is_changed)
            is_changed = true;
        }
        else {
          temp_group_size.push_back(group_speed[i]);
        }
      }
    }
    if(*temp_group_size.rbegin() < *group_speed.rbegin())
      temp_group_size.push_back(*group_speed.rbegin());

    group_speed = temp_group_size;
  }

  printf("%lu\n", group_speed.size());

  return 0;
}
