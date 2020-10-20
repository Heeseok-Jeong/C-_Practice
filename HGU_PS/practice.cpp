#include <iostream>
#include <queue>
using namespace std;

struct compare{
	bool operator()(pair<long long, long long> a, pair<long long, long long> b){
        if (a.first != b.first) return a.first > b.first;
	    else return a.second < b.second;
	}
};

int main(){
    long long n, k;
    long long numOfPeople, point, sum = 0, max_people = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, compare> pq;

    scanf("%lld %lld", &n, &k);
    for(long long i = 0; i < n; i++){
        scanf("%lld %lld", &numOfPeople, &point);

        pq.push(make_pair(point-k, numOfPeople));
        pq.push(make_pair(point+k, numOfPeople-numOfPeople*2));

        if(k == 0 && max_people < numOfPeople) max_people = numOfPeople;
    }

    if(k == 0) {
        printf("%lld", max_people);
        return 0;
    }

    max_people = 0;
    while(!pq.empty()){
        pair<long long, long long> top = pq.top();
				cout << "first : " << top.first << ", second : " << top.second << endl;
        sum += top.second;
        pq.pop();

        if(sum >= max_people) max_people = sum;
	}

    printf("%lld", max_people);
    return 0;
}
