#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v1(6, 1);
  vector<int> v2(7, 10);

  for(auto item : v2)
    cout << item << " ";
  cout << endl;

  v2.assign(10, 5);

  for(auto item : v2)
    cout << item << " ";
  cout << endl;

  return 0;
}
