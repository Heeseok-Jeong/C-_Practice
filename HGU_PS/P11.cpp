#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> visited, final_matching_words_index;
vector<string> words;
bool exist_result = false;

void browse(int x, int d, int n, vector<int> words_index) {
  // cout << words[x] << endl;
  // cout << "w_i : ";
  // for(auto i : words_index) {
  //   cout << words[i] << ", ";
  // }
  // cout << endl;
  if(d == n) {
    exist_result = true;
    final_matching_words_index = words_index;
    // cout << "exit!" << endl;
    return;
  }

  for(int i = 0; i < n; i++) {
    if(i != x && words[x].back() == words[i].front() && !visited[i]) {
      visited[i] = true;
      words_index.push_back(i);
      browse(i, d+1, n, words_index);
      // cout << "out\n";
      visited[i] = false;
      words_index.pop_back();
      if(exist_result)
        return;
    }
  }
}


int main() {
  int n, i, j;
  scanf("%d", &n);
  getchar();
  
  for(i = 0; i < n; i++) {
    string str;
    getline(cin, str);
    words.push_back(str);
  }
  sort(words.begin(), words.end());
  // cout << endl;
  // for(i = 0; i < n; i ++)
  //   cout << words[i] << ", ";
  // cout << endl;

  
  for(i = 0; i < n; i++) {
    if(exist_result)
      break;
    visited.assign(n, false);
    visited[i] = true;
    vector<int> words_index;
    words_index.push_back(i);
    browse(i, 1, n, words_index);
  }

  // cout << "check" << endl;

  if(exist_result) {
    for(auto i : final_matching_words_index)
          cout << words[i] << endl;
  }
  else
    cout << 0 << endl;

  return 0;
}
