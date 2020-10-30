#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n  = 0, i = 0, j = 0, val = 0, asc_count = 0, des_count = 0, max_count = 0;
  vector<int> cards, asc_list, asc_count_list, des_list, des_count_list;
  scanf("%d", &n);

  for(i = 0; i < n; i++) {
    scanf("%d", &val);
    cards.push_back(val);
  }

  for(i = 0; i < n; i++) {
    val = cards[i];
    if(asc_count == 0) {
      asc_list.push_back(val);
      asc_count += 1;
    }
    else {
      if(val > asc_list[asc_count-1]) {
        asc_list.push_back(val);
        asc_count += 1;
      }
      else {
        for(j = asc_count-2; j >= 0; j--) {
          if(val > asc_list[j]) {
            asc_list[j+1] = val;
            break;
          }
        }
        if(j == -1)
          asc_list[j+1] = val;
      }
    }
    asc_count_list.push_back(asc_count);

    val = cards[n-1-i];
    if(des_count == 0) {
      des_list.push_back(val);
      des_count += 1;
    }
    else {
      if(val > des_list[des_count-1]) {
        des_list.push_back(val);
        des_count += 1;
      }
      else {
        for(j = des_count-2; j >= 0; j--) {
          if(val > des_list[j]) {
            des_list[j+1] = val;
            break;
          }
        }
        if(j == -1)
          des_list[j+1] = val;
      }
    }

    des_count_list.push_back(des_count);
  }

  for(i = 0; i < n; i++) {
    if(max_count < asc_count_list[i] + des_count_list[n-1-i])
      max_count = asc_count_list[i] + des_count_list[n-1-i]-1;
  }

  printf("%d\n", max_count);

  return 0;
}
