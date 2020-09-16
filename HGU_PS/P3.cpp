#include <iostream>
#include <vector>
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
  int m, i, j, temp, result, count, size;
  vector<int> arr;

  scanf("%d", &m);
  cout << "m : " << m << endl;
  while(cin >> temp) {
  // while(scanf("%d", &temp) != cin.eof()) {
    arr.push_back(temp);
  }
  // size = i;
  // cout << "size : " << size << endl;
  size = arr.size();
  arr.resize(size);
  for(i=0; i<size; i++) {
    cout << arr[i];
  }
  cout << endl;

  quick_sort_des(arr, 0, size-1);

  for(i=0; i<size; i++) {
    cout << arr[i];
  }
  cout << endl;
}
