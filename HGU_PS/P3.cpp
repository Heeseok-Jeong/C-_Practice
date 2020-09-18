#include <iostream>
#include <vector>
using namespace std;

int n;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int max(int a, int b) {
  if(a > b) return a;
  else return b;
}

void quick_sort_des(vector<int> &arr, int start, int end) {
  if(start >= end) {
    return;
  }
  int pivot = start;
  int up = start+1;
  int down = end;
  while(up <= down) {
    while(up <= end && arr[up] >= arr[pivot]) {
      up++;
    }
    while(down > start && arr[down] <= arr[pivot]) {
      down--;
    }
    if(up > down) {
      swap(arr[down], arr[pivot]);
    } else {
      swap(arr[up], arr[down]);
    }
  }
    quick_sort_des(arr, start, down-1);
    quick_sort_des(arr, down+1, end);
}

int main() {
  int m, i, j, temp, result, size, over, a_under, new_a_under;
  vector<int> arr;

  scanf("%d", &m);
  over = 0;
  while(cin >> temp) {
    if(temp > m/2) {
      over++;
    }
    arr.push_back(temp);
  }
  size = arr.size();
  a_under = size - over;
  arr.resize(size);

  quick_sort_des(arr, 0, size-1);

  new_a_under = a_under;
  j = size-1;
  for(i = 0; i < over; i++) {
    if(arr[i]+arr[j] <= m) {
      j--;
      new_a_under--;
    }
  }

  if(new_a_under%2 == 0) {
    result = new_a_under/2;
  } else {
    result = new_a_under/2 + 1;
  }

  result += over;

  printf("%d", result);

  return 0;
}
