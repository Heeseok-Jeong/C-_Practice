#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

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
    // cout << "back : " << word.back() << ", " << int(word.back())
    alpha_degrees[int(word.back())-97].second += 1;
    alpha_degrees[int(word.front())-97].first += 1; 
    
  }

  int start_count = 0;
  int end_count = 0;
  bool possible = false;
  for(i = 0; i < 26; i++) {
    if(start_count > 1 || end_count > 2)
      break;
    int in_degree = alpha_degrees[i].first;
    int out_degree = alpha_degrees[i].second;
    if(in_degree + 1 == out_degree && in_degree != 0)
      start_count += 1;
    else if(in_degree == out_degree + 1 && out_degree != 0)
      end_count += 1;
    else if(in_degree != out_degree){
      break;
    }
    cout << static_cast<char> (i+97) << " : " << alpha_degrees[i].first << ", " << alpha_degrees[i].second << endl;
  }

  if(start_count == 1 && end_count == 1)
    possible = true;

  cout << possible << endl;

  return 0;
}
