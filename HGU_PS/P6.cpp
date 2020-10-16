#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_SQUARE_SIDE = 8;
const int MAX_N = 5;
const int MAX_POLY_SIDE = 4;

int h_arr[MAX_N] = {0};
int w_arr[MAX_N] = {0};
int poly[MAX_N][MAX_POLY_SIDE][MAX_POLY_SIDE] = {0};
int square[MAX_SQUARE_SIDE][MAX_SQUARE_SIDE] = {0};
int sorted_index_list[MAX_N] = {0};
bool found_answer = false;
vector<vector<vector<int> > > possible_point;

void make_square(int depth, int n, int x, int pre_square[][MAX_SQUARE_SIDE]) {
  int a, b, i, j, k, sorted_index = 0;
  int cur_square[MAX_SQUARE_SIDE][MAX_SQUARE_SIDE] = {0};

  if(depth == n) {
    found_answer = true;
    for(int j = 0; j < MAX_SQUARE_SIDE; j++) {
      for(int k = 0; k < MAX_SQUARE_SIDE; k++) {
        square[j][k] = pre_square[j][k];
      }
    }
    return;
  }

  sorted_index = sorted_index_list[depth];
  for(i = 0; (i < possible_point[sorted_index].size()) && !found_answer; i++) {
    bool is_duplicated = false;
    a = possible_point[sorted_index][i][0];
    b = possible_point[sorted_index][i][1];

    for(j = 0; j < MAX_SQUARE_SIDE; j++) {
      for(k = 0; k < MAX_SQUARE_SIDE; k++) {
        cur_square[j][k] = pre_square[j][k];
      }
    }

    for(j = 0; j < h_arr[sorted_index] && !is_duplicated; j++) {
      for(k = 0; k < w_arr[sorted_index]; k++) {
        if(cur_square[j+a][k+b] == 0)
          cur_square[j+a][k+b] = poly[sorted_index][j][k];
        else if(poly[sorted_index][j][k] != 0) {
          is_duplicated = true;
          break;
        }
      }
    }

    if(!is_duplicated)
      make_square(depth+1, n, x, cur_square);
  }
}

int main() {
  int x, n, i, j, k, total_count = 0;
  multimap<int, int, greater<int> > sorted_each_count;

  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    int h, w, each_count = 0;
    scanf("%d %d", &h, &w);
    h_arr[i] = h;
    w_arr[i] = w;
    for(j = 0; j < h; j++) {
      for(k = 0; k < w; k++) {
        int value = 0;
        scanf("%d", &value);
        if(value == 1)
          poly[i][j][k] = i+1;
        total_count += value;
        each_count += value;
      }
    }
    sorted_each_count.insert(pair<int, int>(each_count, i));
  }

  i = 0;
  for(auto it = sorted_each_count.begin(); it != sorted_each_count.end(); it++) {
    sorted_index_list[i++] = it->second;
  }

  for(x = 1; x <= MAX_SQUARE_SIDE && total_count != x*x; x++) {}

  for(i = 0; i < n; i++) {
    vector<vector<int> > point_list;
    for(j = 0; j <= x-h_arr[i]; j++) {
      for(k = 0; k <= x-w_arr[i]; k++) {
        vector<int> point;
        point.push_back(j);
        point.push_back(k);
        point_list.push_back(point);
      }
    }
    possible_point.push_back(point_list);
  }

  int depth = 0;
  int init_square[MAX_SQUARE_SIDE][MAX_SQUARE_SIDE] = {0};
  make_square(depth, n, x, init_square);

  if(found_answer && x <= MAX_SQUARE_SIDE) {
    for(i = 0; i < x; i++) {
      for(j = 0; j < x; j++) {
        printf("%d ", square[i][j]);
      }
      printf("\n");
    }
  }
  else
    printf("No solution possible\n");

  return 0;
}
