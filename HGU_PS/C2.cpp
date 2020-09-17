#include <iostream>
using namespace std;

int n;

struct Point {
  int val;
  bool visited;
  int memo;
};

int min(int a, int b) {
  if(a > b) return b;
  else return a;
}

int compute_difficulty(Point arr[][500], int row, int col) {
  // cout << "row : " << row <<", col : " << col << endl;
  if(arr[row][col].visited) return arr[row][col].memo;
  int val = arr[row][col].val;
  int temp = val;
  arr[row][col].visited = true;

  //상
  if(row != 0 && arr[row-1][col].val < val) {
    temp = min(temp, compute_difficulty(arr, row-1, col));
  }
  // 하
  if(row != n-1 && arr[row+1][col].val < val) {
    temp = min(temp, compute_difficulty(arr, row+1, col));
  }
  // 좌
  if(col != 0 && arr[row][col-1].val < val) {
    temp = min(temp, compute_difficulty(arr, row, col-1));
  }
  // 우
  if(col != n-1 && arr[row][col+1].val < val) {
    temp = min(temp, compute_difficulty(arr, row, col+1));
  }

  arr[row][col].memo = temp;
  return arr[row][col].memo;
}

int main() {
  int i, j, temp, result = 0;
  scanf("%d", &n);
  Point arr[500][500];

  //입력
  for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
      scanf("%d", &temp);
      arr[i][j].val = temp;
    }
  }

  for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
      temp = arr[i][j].val - compute_difficulty(arr, i, j);
      if(result < temp) {
        result = temp;
      }
      // cout << "i : " << n*i+j << ", temp : " << temp << ", result : " << result << endl;
    }
  }

  // for(i=0;i<n;i++) {
  //   for(j=0;j<n;j++) {
  //     cout << arr[i][j].val << " ";
  //   }
  // cout << endl;
  // }
  // cout << endl;


// 4
// 1 6 10 3
// 5 5 6 1
// 5 7 2 3
// 11 5 7 4

  printf("%d\n", result);
  return 0;
}
