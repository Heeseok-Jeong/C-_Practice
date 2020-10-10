#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, src, dst, result = 0;
  vector<vector<int> > graphs;
  vector<vector<int> >::iterator it_vv;
  vector<int> line;
  vector<int>::iterator it_v;

  scanf("%d %d", &n, &m);

  scanf("%d %d", &src, &dst);
  line.push_back(src);
  line.push_back(dst);
  graphs.push_back(line);

  for(int i = 1; i < m; i++) {
    scanf("%d %d", &src, &dst);
    if(result == 0) {
      bool is_src_in = false;
      bool is_dst_in = false;

      for(int j = 0; j < graphs.size(); j++) {
        if(find(graphs[j].begin(), graphs[j].end(), src) != graphs[j].end())
          is_src_in = true;
        if(find(graphs[j].begin(), graphs[j].end(), dst) != graphs[j].end())
          is_dst_in = true;

        if(is_src_in && is_dst_in) {
          result =  i+1;
          break;
        }
        else if(is_src_in)
          graphs[j].push_back(dst);
        else if(is_dst_in)
          graphs[j].push_back(src);
        else {
          line.push_back(src);
          line.push_back(dst);
          graphs.push_back(line);
        }
      }
    }
    else {
      break;
    }
  }

  printf("%d\n", result);
  return 0;
}
