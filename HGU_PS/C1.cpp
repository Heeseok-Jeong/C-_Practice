#include <iostream>
using namespace std;

int main() {
  int n, k, f, i, j, x, y, count;
  bool flag = true;
  cin >> n >> k >> f;
  int arr[n+1][n+1];

  for(i = 0; i < n+1; i++) {
    for(j = 0; j < n+1; j++) {
      arr[i][j] = 0;
      // cout << arr[i][j] << " ";
    }
    // cout << endl;
  }

  for(i = 0; i < f; i++) {
    cin >> x >> y;
    arr[x][y] = 1;
    arr[y][x] = 1;
  }

  for(i = 1; i < n+1; i++) {
    count = 0;
    for(j = 1; j < n+1; j++) {
      // cout << arr[i][j] << " ";
      if(arr[i][j] == 1) {
        count++;
      }
    }
    arr[i][0] = count;
    // cout << endl << i << " : " << arr[i][0] << endl;
  }

  // for(i = 0; i < n+1; i++) {
  //   for(j = 0; j < n+1; j++) {
  //     cout << arr[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  while(flag) {
    flag = false;
    for(i = 1; i < n+1; i++) {
      x = arr[i][0];
      if(x > 0 && x < k) {
        arr[i][0] = 0;
        if(flag == false) {
          flag = true;
        }
        for(j = 1; j < n+1; j++) {
          y = arr[i][j];
          if(y == 1) {
            arr[i][j] = 0;
            arr[j][i] = 0;
            arr[j][0]--;
          }
        }
        // for(i = 0; i < n+1; i++) {
        //   for(j = 0; j < n+1; j++) {
        //     cout << arr[i][j] << " ";
        //   }
        //   cout << endl;
        // }
        // cout << endl;
      }
    }
  }

  // cout << endl;
  // for(i = 0; i < n+1; i++) {
  //   for(j = 0; j < n+1; j++) {
  //     cout << arr[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  count = 0;
  for(i = 1; i < n+1; i++) {
    if(arr[i][0] >= k) {
      count++;
    }
  }
  printf("%d\n", count);

  return 0;
}
