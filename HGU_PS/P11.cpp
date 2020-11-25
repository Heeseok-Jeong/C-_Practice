#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void browse_next_word() {


}

int main() {
  int n, i, j;
  scanf("%d", &n);
  getchar();
  vector<string> words;
  for(i = 0; i < n; i++) {
    string str;
    getline(cin, str);
    words.push_back(str);
  }
  sort(words.begin(), words.end());
  // for(i = 0; i < n; i ++)
  //   cout << words[i] << ", ";

  vector<int> 


  return 0;
}
