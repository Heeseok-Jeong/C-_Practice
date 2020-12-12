#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long min, max, i, j, ans;
    scanf("%lld %lld", &min, &max);
    ans = max-min+1;

    vector<bool> sieve(ans, false);
    for(i = 2; i*i <= max; i++) {
        long long min_q = min/(i*i);
        if(min%(i*i) != 0)
            min_q += 1;
        
        while(i*i*min_q <= max) {
            if(sieve[i*i*min_q - min] == false) {
                sieve[i*i*min_q - min] = true;
                ans -= 1;
            }
            min_q += 1;    
        }
    }

    cout << ans << endl;
    return 0;
}