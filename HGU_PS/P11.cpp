#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int graph[26][26] = {0};
bool done = false;
vector<int> words_index;

void browse(int x, int d, int n) {
  words_index.push_back(x);
  for(int i = 0; i < words_index.size(); i++) {
    cout << words_index[i] << ", ";
  }
  cout << endl;
  if(d == n) {
    done = true;
    return;
  }
  
  for(int i = 0; i < 26; i++) {
    if(graph[x][i] > 0) {
      graph[x][i] -= 1;
      browse(i, d+1, n);
    }
  }
  
}

int main() {
  int n, i, j;
  scanf("%d", &n);

  pair<int, int> alpha_degrees[26];
  for(i = 0; i < 26; i++) {
    alpha_degrees[i].first = 0;
    alpha_degrees[i].second = 0;
  }
  vector<string> words;
  for(i = 0; i < n; i++) {
    string word;
    cin >> word;
    words.push_back(word);
    alpha_degrees[int(word.front())-97].second += 1;
    alpha_degrees[int(word.back())-97].first += 1; 
  }

  for(i = 0; i < 26; i++) {
    cout << static_cast<char> (i+97) << " : " << alpha_degrees[i].first << ", " << alpha_degrees[i].second << endl;
  }

  int start_count = 0;
  int end_count = 0;
  bool trail_possible = false;
  bool circle_possible = true;
  int start_i = 0;
  for(i = 0; i < 26; i++) {
    int in_degree = alpha_degrees[i].first;
    int out_degree = alpha_degrees[i].second;
    if(in_degree + 1 == out_degree) {
      start_count += 1;
      start_i = i;
      circle_possible = false;
    }
    else if(in_degree == out_degree + 1) {
      end_count += 1;
      circle_possible = false;
    }
    else if(in_degree != out_degree){
      break;
      circle_possible = false;
    }
  }

  if((start_count == 1 && end_count == 1))
    trail_possible = true;

  if(trail_possible)
    cout << "trail\n";
  else if(circle_possible)
    cout << "circle\n";
  else
    cout << "nothing\n";

  if(trail_possible || circle_possible) {
    sort(words.begin(), words.end());
    for(i = 0; i < n; i++) {
      // cout << words[i] << endl;
      int from = int(words[i].front())-97;
      int to = int(words[i].back())-97;
      graph[from][to] += 1;
    }

    for(i = 0; i < 26; i++) {
      for(j = 0; j < 26; j++) {
        cout << graph[i][j] << ", ";
      }
      cout << endl;
    }
    // graph[start_i][start_i] -= 1;
    browse(start_i, 1, n);

    if(done) {
      for(i = 0; i < words_index.size(); i++)
        cout << words[words_index[i]] << endl;
    }
    else
      printf(0);
    }
  else {
    printf(0);
  }
  
  

  return 0;
}
