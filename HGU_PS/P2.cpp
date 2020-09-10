#include <iostream>
using namespace std;

int max(int a, int b) {
  if(a > b) return a;
  else return b;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// void q_sort_by_x(int x[], int g[], int l, int r) {
//   if(l >= r) return;
//   int pivot = l;
//   int start = l+1;
//   int end = r;
//   while(start<=end) {
//     while(x[pivot] >= x[start] && start <= r) {
//       start++;
//     }
//     while(x[pivot] <= x[end] && start > r) {
//       end--;
//     }
//     if(start > end) {
//       swap(x[pivot], x[end]);
//       swap(g[pivot], g[end]);
//     } else {
//       swap(x[start], x[end]);
//       swap(g[start], g[end]);
//     }
//   }
//   q_sort_by_x(x, g, l, end-1);
//   q_sort_by_x(x, g, end+1, r);
// }

void q_sort_by_x(int list[], int list2[], int left, int right)
{
	if (left >= right)
		return;
	int pivot = left;
	int start = left + 1;
	int end = right;
	while (start<=end)
	{
		while (list[pivot] >= list[start] && start <= right)
			start++;
		while (list[pivot] <= list[end] && end > left)
			end--;
		if (start > end)
		{
			swap(list[pivot], list[end]);
      swap(list2[pivot], list2[end]);
		}
		else
			swap(list[start], list[end]);
      swap(list2[start], list2[end]);
	}
	q_sort_by_x(list, list2, left, end - 1);
	q_sort_by_x(list, list2, end + 1, right);
}

int main() {
  int n, k, result, i, j, y, z, temp;
  cin >> n >> k;
  int x[n];
  int g[n];

  for(i = 0; i < n; i++) {
    cin >> g[i] >> x[i];
  }

  cout << endl;
  for(i = 0; i < n; i++) {
    cout << x[i] << " ";
  }
  cout << endl;
  for(i = 0; i < n; i++) {
    cout << g[i] << " ";
  }
  cout << endl << endl;

  q_sort_by_x(x, g, 0, n-1);
  for(i = 0; i < n; i++) {
    cout << x[i] << " ";
  }
  cout << endl;
  for(i = 0; i < n; i++) {
    cout << g[i] << " ";
  }
  cout << endl;

  // for(i = 0; i < n; i++) {
  //   if(i == n) {
  //     max(result, g[i]);
  //   } else {
  //     y = x[i] + k;
  //     for(j = i; (z=x[j]) <= y+k; j++) {
  //       if(z)
  //     }
  //     if(i == n-1 && y == x[n-1]) {
  //       break;
  //     }
  //   }
  // }

  printf("%d\n", result);

  return 0;
}
