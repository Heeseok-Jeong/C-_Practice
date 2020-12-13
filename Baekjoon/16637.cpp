#include <iostream>
#include <vector>
#include <string>

using namespace std;

int calc(int x, string op, int y) {
    if(op == '+') {
        return x + y;
    }
    else if(op == '-') {
        return x - y;
    }
    else {
        return x * y;
    }
}

int main() {
    int n, i, j, num_count, op_count;
    scanf("%d", &n);
    num_count = n/2 + 1;
    op_count = n/2;
    string input_str;
    cin >> input_str;

    vector<pair<int, int> > memo(num_count);
    string op(input_str[1]);
    memo[0][0] = calc(int(input_str[0]), string(input_str[1]), int(input_str[1]));

    for(i = 0; i < num_count; i++) {
        
    } 

    return 0;
}