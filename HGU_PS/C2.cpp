#include <iostream>
#include <list>
using namespace std;

int n;

struct Point {
  int x;
  int y;
};

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int max(int a, int b) {
  if(a > b) return a;
  else return b;
}

void quick_sort_des(int arr[][500], Point order[n*n]) {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {

    }
  }
}

int compute_difficulty(int arr[][500], int start, int row, int col, int result) {
  int temp;
  int val = arr[row][col];
  // cout << "row : " << row <<", col : " << col << endl;
  if(val == -1) {
    return result;
  }

  //상
  if(row != 0 && arr[row-1][col] < val) {
    result = max(result, compute_difficulty(arr, start, row-1, col, result));
  }
  // 하
  if(row != n-1 && arr[row+1][col] < val) {
    result = max(result, compute_difficulty(arr, start, row+1, col, result));
  }
  // 좌
  if(col != 0 && arr[row][col-1] < val) {
    result = max(result, compute_difficulty(arr, start, row, col-1, result));
  }
  // 우
  if(col != n-1 && arr[row][col+1] < val) {
    result = max(result, compute_difficulty(arr, start, row, col+1, result));
  }
  // cout << result << endl;
  arr[row][col] = -1;
  return max(result, start-val);
}

int main() {
  int i, j, result, row, col, val, gap, small, temp;
  scanf("%d", &n);
  int arr[500][500], arr2[25000];
  Point order[n*n], p;
  list<Point> stack;

  //입력
  for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
      scanf("%d", &temp);
      arr[i][j] = temp;
      arr2[n*i+j] = temp;
    }
  }
  //값순서 내림차순 정렬 -> order[0]에는 값이 가장 큰 좌표 [x, y] 있음
  // quick_sort_des(arr, order);
  for(i=0;i<n*n;i++) {
    scanf("%d %d", &p.x, &p.y);
    order[i] = p;
  }


  // for(i=0;i<n*n;i++) {
  //   cout << order[i].x << " " << order[i].y << ", ";
  // }
  // cout << endl;
// 4
// 1 6 10 3
// 5 5 6 1
// 5 7 2 3
// 11 5 7 4
// 3 0
// 0 2
// 2 1
// 3 2
// 0 1
// 1 2
// 1 0
// 1 1
// 2 0
// 3 1
// 3 3
// 0 3
// 2 3
// 2 2
// 0 0
// 1 3
  // cout << "1 : " << arr << endl;
  // result = max(result, compute_difficulty(arr, 1, 1, 1, result));

  //order 순서대로 돌기
  small = arr[order[n*n-1].x][order[n*n-1].y];
  for(i = 0; i < n*n; i++) {
    // cout << "i : " << i << endl;
    row = order[i].x;
    col = order[i].y;
    val = arr[row][col];
    if(val == -1) {
      continue;
    }
    gap = val - small;

    //종료조건
    if(result >= gap) {
      // for(j=0;j<n;j++) {
      //   for(int k=0;k<n;k++) {
      //     cout << arr[j][k] << " ";
      //   }
      //   cout << endl;
      // }
      printf("%d\n", result);
      return 0;
    }

    result = max(result, compute_difficulty(arr, val, row, col, result));
  }
  // printf("another : %d\n", result);
  return 0;
}
