#include<iostream>
#include<algorithm>
using namespace std;
int N, K;
const int maxn = 2e4+10;
struct peo{
	int id, score;
};
peo people[maxn];
bool cmp(peo a, peo b) {
	return a.score!=b.score?a.score>b.score:a.id<b.id;
}
int E[11];

int main()
{
	int i, val;
	cin>>N>>K;
	for(i=1;i<=10;i++) cin>>E[i];
	for(i=1;i<=N;i++) {
		cin>>people[i].score;
		people[i].id = i;
	}
	sort(people+1, people+1+N, cmp);
	for(i=1;i<=N;i++) {
		people[i].score += E[(i-1) % 10 +1];
	}
	sort(people+1, people+1+N, cmp);
	for(i=1;i<=K;i++) {
		cout<<people[i].id<<" ";
	}
	return 0;
}
