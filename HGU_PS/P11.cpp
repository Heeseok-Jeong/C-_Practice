#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> graph_arr[1000], memo[1000], visited, final_matching_words_index;
bool exist_result = false;

void browse_all_matching_words(int d, int n, int word_index, vector<int> matching_words_index) {
  matching_words_index.push_back(word_index);
  cout << "d = " << d << ", word_index = " << word_index << " || ";
  for(auto x : matching_words_index) {
    cout << x << ", ";
  }
  cout << endl;

  if(d == n) {
    if(exist_result) {
      for(int i = 0; i < n; i ++) {
        if(final_matching_words_index[i] < matching_words_index[i])
          final_matching_words_index = matching_words_index;
      }
    }
    else {
      exist_result = true;
      final_matching_words_index = matching_words_index;
    }

    return;
  }

  visited[word_index] = true;

  for(int i = 0; i < n; i++) {
    if(i != word_index)
      if(graph_arr[word_index][i] == 1 && !visited[i]) {
        browse_all_matching_words(d+1, n, i, matching_words_index);
        visited[i] = false;
      }
  }
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
  cout << endl;
  for(i = 0; i < n; i ++)
    cout << words[i] << ", ";
  cout << endl;


  for(i = 0; i < n; i++) {
    graph_arr[i].assign(n, 0);
  }

  for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
      if(i != j)
        if(words[i].back() == words[j].front())
          graph_arr[i][j] = 1;
    }
  }

  for(i = 0; i < n ; i++) {
    for(j = 0; j < n; j++) {
      cout << graph_arr[i][j] << ", ";
    }
    cout << endl;
  }

  visited.assign(n, 0);
  vector<int> matching_words_index;
  browse_all_matching_words(1, n, 0, matching_words_index);

  if(exist_result) {
    for(i = 0; i < n; i++) {
      cout << words[i] << endl;
    }
  }
  else
    cout << 0 << endl;

  return 0;
}
