#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, i, j = 0;
  vector<int> cards, asc_memo, des_memo;
  scanf("%d", &n);

  for(i = 0; i < n; i++) {
    int num = 0;
    scanf("%d", &num);
    cards.push_back(num);
  }

  asc_memo.assign(n, 1);
  des_memo.assign(n, 0);

  for(i = 1; i < n; i++) {
    for(j = 0; j < i; j++) {
      if(cards[i] > cards[j] && asc_memo[i] < asc_memo[j]+1)
        asc_memo[i] = asc_memo[j]+1;
    }

    if(cards[i] < cards[i-1]) {
      des_memo[i] = asc_memo[i-1]+1;
      for(j = 0; j < i; j++) {
        if(cards[i] < cards[j] && des_memo[i] < des_memo[j]+1)
          des_memo[i] = des_memo[j]+1;
      }
    }
  }

  int max_card_count = 0;
  for(i = 0; i < n; i++) {
    if(max_card_count < asc_memo[i])
      max_card_count = asc_memo[i];
    if(max_card_count < des_memo[i])
      max_card_count = des_memo[i];
  }

  printf("%d\n", max_card_count);

  // cout << "cards : ";
  // for(i = 0; i < n; i++) {
  //   // num = cards[i];
  //   // if(max < num) {
  //   //   max_index = i;
  //   //   max = num;
  //   // }
  //   cout << cards[i] << " ";
  // }
  // cout << endl;

  return 0;
}
