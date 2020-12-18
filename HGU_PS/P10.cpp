#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, b, i, j, ans = 0;
  scanf("%d %d", &n, &b);
  vector<int> weights(n+1, 0);
  for(i = 0; i < n; i++) {
    int weight;
    scanf("%d", &weight);
    weights[i]=  weight;
    if(ans < weight)
      ans = weight;
  }

  vector<int> vessels[450];
  for(i = 0; i < 450; i++)
    vessels[i].assign(n+1, 0);
  vector<vector<int> > cluster_2;
  for(i = 0; i < b; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a -= 1;
    b -= 1;
    vessels[a][b] = 1;
    vessels[b][a] = 1;
    if(ans < weights[a]+weights[b])
      ans = weights[a]+weights[b];
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    cluster_2.push_back(v);
  }

  vector<vector<int> > cluster_3;
  for(i = 0; i < cluster_2.size(); i++) {
    for(j = 0; j < n; j++) {
      if(vessels[j][cluster_2[i][0]] == 1 && vessels[j][cluster_2[i][1]] == 1) {
        vector<int> v;
        v.push_back(j);
        v.push_back(cluster_2[i][0]);
        v.push_back(cluster_2[i][1]);
        cluster_3.push_back(v);
        if(ans < weights[j] + weights[cluster_2[i][0]] + weights[cluster_2[i][1]])
          ans = weights[j] + weights[cluster_2[i][0]] + weights[cluster_2[i][1]];
      }
    }
  }

  for(i = 0; i < cluster_3.size(); i++) {
    for(j = 0; j < n; j++) {
      if(vessels[j][cluster_3[i][0]] == 1 && vessels[j][cluster_3[i][1]] == 1 && vessels[j][cluster_3[i][2]] == 1) { 
        if(ans < weights[j] + weights[cluster_3[i][0]] + weights[cluster_3[i][1]] + weights[cluster_3[i][2]])
          ans = weights[j] + weights[cluster_3[i][0]] + weights[cluster_3[i][1]] + weights[cluster_3[i][2]];
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}



// #include <iostream>
// #include <vector>
// #include <tuple>

// using namespace std;

// int main() {
//   int n, b, i, j, ans = 0;
//   scanf("%d %d", &n, &b);
//   vector<int> weights;
//   for(i = 0; i < n; i++) {
//     int weight;
//     scanf("%d", &weight);
//     weights.push_back(weight);
//     if(ans < weight)
//       ans = weight;
//   }
//   vector<int> vessels[450];
//   for(i = 0; i < 450; i++)
//     vessels[i].assign(n, 0);
//   typedef vector<tuple<int, int> > c2;
//   c2 cluster_2;
//   for(i = 0; i < b; i++) {
//     int a, b;
//     scanf("%d %d", &a, &b);
//     vessels[a][b] = 1;
//     vessels[b][a] = 1;
//     if(ans < weights[a]+weights[b])
//       ans = weights[a]+weights[b];
//     cluster_2.push_back(make_tuple(a, b));
//   }

//   typedef vector<tuple<int, int, int> > c3;
//   c3 cluster_3;
//   for(auto it = cluster_2.begin(); it != cluster_2.end(); it++) {
//     for(i = 0; i < n; i++) {
//       if(vessels[i][get<0>(*it)] == 1 && vessels[i][get<1>(*it)] == 1) {
//         cluster_3.push_back(make_tuple(get<0>(*it), get<1>(*it), i));
//         if(ans < weights[get<0>(*it)] + weights[get<1>(*it)] + weights[i])
//           ans = weights[get<0>(*it)] + weights[get<1>(*it)] + weights[i];
//       }
//     }
//   }

//   for(auto it = cluster_3.begin(); it != cluster_3.end(); it++) {
//     for(i = 0; i < n; i++) {
//       if(vessels[i][get<0>(*it)] == 1 && vessels[i][get<1>(*it)] == 1 && vessels[i][get<2>(*it)] == 1) {
//         if(ans < weights[get<0>(*it)] + weights[get<1>(*it)] + weights[get<2>(*it)] + weights[i])
//           ans < weights[get<0>(*it)] + weights[get<1>(*it)] + weights[get<2>(*it)] + weights[i];
//       }
//     }
//   }

//   printf("%d\n", ans);

//   return 0;
// }
