#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 5010;
struct peo{
	int id, score;
};
peo people[maxn];
int N, M;
bool cmp(peo a, peo b) {
	return a.score!=b.score?a.score>b.score:a.id<b.id;
}

int main()
{
	int i;
	cin>>N>>M;
	M = (int)(M*1.5);
	for(i=1;i<=N;i++) {
		cin>>people[i].id>>people[i].score;
	}
	sort(people+1, people+N+1, cmp);
	int target = people[M].score;
	while(people[M].score>=target) M++;
	M--;
	cout<<target<<" "<<M<<endl;
	for(i=1;i<=M;i++) {
		cout<<people[i].id<<" "<<people[i].score<<endl;
	}
	return 0;
}
