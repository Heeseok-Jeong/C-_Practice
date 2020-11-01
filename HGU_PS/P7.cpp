#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, i, p, spent_time;
  vector<int> p_v;
  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf("%d", &p);
    p_v.push_back(p);
  }

  int cnt_p = n;
  while(true) {
    vector<int> temp_p_v;
    if(cnt_p == 1) {
      printf("%d\n", spent_time);
      break;
    }
    else if(cnt_p == 2) {
      spent_time += p_v[0] + p_v[1];
      temp_p_v.push_back(p_v[0] + p_v[1]);
      cnt_p -= 1;
    }
    else if(cnt_p == 3) {
      if(p_v[0] < p_v[2]) {
        spent_time += p_v[0] + p_v[1];
        temp_p_v.push_back(p_v[0] + p_v[1]);
        temp_p_v.push_back(p_v[2]);
      }
      else {
        spent_time += p_v[1] + p_v[2];
        temp_p_v.push_back(p_v[0]);
        temp_p_v.push_back(p_v[1] + p_v[2]);
      }
      cnt_p -= 1;
    }
    else {
      int min_four_sum = p_v[0] + p_v[1] + p_v[2] + p_v[3];
      int min_four_sum_i = 0;
      for(i = 1; i < cnt_p-3; i++) {
        if(min_four_sum > p_v[i] + p_v[i+1] + p_v[i+2] + p_v[i+3]) {
            min_four_sum = p_v[i] + p_v[i+1] + p_v[i+2] + p_v[i+3];
            min_four_sum_i = i;
        }
      }
      vector<int> four_ele_sum_v;
      four_ele_sum_v.push_back(2*(p_v[min_four_sum_i] + p_v[min_four_sum_i+1]) + p_v[min_four_sum_i+2]);
      four_ele_sum_v.push_back(2*(p_v[min_four_sum_i+1] + p_v[min_four_sum_i+2]) + p_v[min_four_sum_i]);
      four_ele_sum_v.push_back(2*(p_v[min_four_sum_i+1] + p_v[min_four_sum_i+2]) + p_v[min_four_sum_i+3]);
      four_ele_sum_v.push_back(2*(p_v[min_four_sum_i+2] + p_v[min_four_sum_i+3]) + p_v[min_four_sum_i+1]);
      four_ele_sum_v.push_back(p_v[min_four_sum_i] + p_v[min_four_sum_i+1] + p_v[min_four_sum_i+2] + p_v[min_four_sum_i+3]);
      int min_sum = four_ele_sum_v[0];
      for(i = 1; i < 5; i++) {
        if(min_sum > four_ele_sum_v[i])
          min_sum = four_ele_sum_v[i];
      }

      min_sum += p_v[min_four_sum_i] + p_v[min_four_sum_i+1] + p_v[min_four_sum_i+2] + p_v[min_four_sum_i+3];
      spent_time += min_sum;
      for(i = 0; i < min_four_sum_i; i++) {
        temp_p_v.push_back(p_v[i]);
      }
      // temp_p_v.push_back(min_sum);
      temp_p_v.push_back(p_v[min_four_sum_i] + p_v[min_four_sum_i+1] + p_v[min_four_sum_i+2] + p_v[min_four_sum_i+3]);
      for(i = min_four_sum_i+4; i < cnt_p; i++) {
        temp_p_v.push_back(p_v[i]);
      }
      cnt_p -= 3;
      // cout << "min_f_s_i : " << min_four_sum_i << endl;
      // cout << "cnt_p : " << cnt_p << endl;
      // cout << "min_sum : " << min_sum << endl;
    }
    p_v = temp_p_v;
    // for(i = 0; i < cnt_p; i++)
    //   cout << p_v[i] << " ";
    // cout << endl;
  }

  return 0;
}
