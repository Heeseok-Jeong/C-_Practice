#include <iostream>
using namespace std;

int main(){
  int n, x = 0;

  cin >> n >> x;

  int i;
  int arr[n];

  for(i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for(i = 0; i < n; i++) {
    if(arr[i] < x) {
      cout << arr[i] << " ";
    }
  }
  cout << endl;
}
