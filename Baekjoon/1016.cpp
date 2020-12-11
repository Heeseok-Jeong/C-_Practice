#include <iostream>
#include <vector>

using namespace std;

const int LIMIT_NUM = 10^6;
vector<bool> is_square_num, is_visit;

int main() {
    long long min, max;
    int n, i, j, count;
    scanf("%lld %lld", &min, &max);
    n = max-min+1;
    count = n-1;
    is_square_num.assign(LIMIT_NUM+1, false);
    is_visit.assign(LIMIT_NUM+1, false);
    vector<bool> results;
    results.assign(n, false);
    
    for(i = 2; i < LIMIT_NUM+1; i++) {
        if(i > max)
            break;
        
        if(!is_square_num[i]) {
            int temp = i;
            if(!is_visit[i]) {
                while(temp <= max) {
                    if(!is_visit[temp]) {
                        is_visit[temp] = true;
                    }
                    temp *= i;
                }
            }
            else {
                while(temp <= max) {
                    if(!is_square_num[temp]) {
                        is_square_num[temp] = true;
                        if(min <= temp && temp <= max) {
                            count--;
                            cout << "temp : " << temp << endl;
                        }
                    }
                    temp *= i;
                }
            }
        }
    }

    cout << count << endl;
    




    return 0;
}