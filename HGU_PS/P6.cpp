#include <iostream>

using namespace std;

int main() {
  int x, n, i, j, k, count = 0;
  int h_arr[5] = {0};
  int w_arr[5] = {0};
  int poly[5][4][4] = {0};
  int possible[5][4][4] = {0};
  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    int h, w = 0;
    scanf("%d %d", &h, &w);
    h_arr[i] = h;
    w_arr[i] = w;
    for(j = 0; j < h; j++) {
      for(k = 0; k < w; k++) {
        int value = 0;
        scanf("%d", &value);
        if(value == 1)
          poly[i][j][k] = i+1;
        count += value;
      }
    }
  }

  bool is_answer = false
  int form[4][4] = {0};
  for(x = 1; x < 5; i++) {
    if(count == i^2) {
      for(i = 0; i < n; i++) {
        for(j = 0; j <= x-h_arr[i]; j++) {
          possible[i]
        }
      }

      break;
    }
  }

  if(is_answer) {
    for(i = 0; i < 4; i++) {
      for(j = 0; j < 4; j++) {
        if(form[i][j] != 0)
          printf("%d ", form[i][j]);
      }
      printf("\n");
    }
  }
  else
    printf("No solution possible\n");




  // cout << "h_arr : ";
  // for(i = 0; i < n; i++) {
  //   cout << h_arr[i] << " ";
  // }
  // cout << endl << endl;;
  //
  // cout << "w_arr : ";
  // for(i = 0; i < n; i++) {
  //   cout << w_arr[i] << " ";
  // }
  // cout << endl << endl;
  //
  // cout << "poly" << endl;
  // for(i = 0; i < n; i++) {
  //   cout << "i : " << i << endl;
  //   for(j = 0; j < h_arr[i]; j++) {
  //     for(k = 0; k < w_arr[i]; k++) {
  //       cout << poly[i][j][k] << " ";
  //     }
  //     cout << endl;
  //   }
  // }
  // cout << "count : " << count << endl;

  return 0;
}
