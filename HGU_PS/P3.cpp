#include <iostream>
#include <vector>
using namespace std;

int n;

struct Carrier {
  bool full;
  int val;
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
  int m, i, j, temp, result, size, over, under;
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
  under = size - over;
  arr.resize(size);

  // for(i=0; i<size; i++) {
  //   cout << arr[i] << " ";
  // }
  // cout << endl;


  quick_sort_des(arr, 0, size-1);

  // for(i=0; i<size; i++) {
  //   cout << arr[i] << " ";
  // }
  // cout << endl;
  // cout << "1 : " << result << endl;
  vector<bool> full(over);
  for(i = over; i < size; i++) {
    temp = arr[i];
    for(j = 0; j < over; j++) {
      if(temp + arr[j] <= m && full[j] == false) {
        // cout << "temp : " << temp << endl;
        under--;
        full[j] = true;
        break;
      }
    }
  }
  if(under%2 == 0) {
    result = under/2;
  } else {
    result = under/2 + 1;
  }
  // cout << "2 : " << result << endl;
  // cout << "over : " << over << endl;
  // cout << "under : " << under << endl;
  // cout << "under after : " << result << endl;
  result += over;
  // cout << "3 : " << result << endl;
  cout << result;
  // cout << result << endl;
  // cout << endl;
  // return 0;
  exit(0);
}
