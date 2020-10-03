#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 2e5+10;
struct peo{
	int score, power, id, ming;
};
peo people[maxn], B[maxn];
bool cmp(peo a, peo b) {
	return a.score!=b.score?a.score>b.score:a.id<b.id;
}

inline int get() {
	int flag=1, val=0;
	char c = getchar();
	while(c<'0' || c>'9') {if(c=='-') flag=-1;c=getchar();}
	while(c>='0' && c<='9') val=(val<<1)+(val<<3)+(c^48),c=getchar();
	return flag*val;
}

void merge(int l, int r) {
	if(l==r) return;
	int mid = l+r>>1;
	merge(l, mid); merge(mid+1, r);
	int i = l, j = mid+1, k = l;
	while(i<=mid && j<=r) {
		if(cmp(people[i], people[j])) B[k++] = people[i++];
		else B[k++] = people[j++];
	}
	while(i<=mid) B[k++] = people[i++];;
	while(j<=r)B[k++] = people[j++];
	for(i=l;i<=r;i++) people[i] = B[i];
}

int main()
{
	int N, R, Q, i, j;
	N=get(), R=get(), Q=get();
	N *= 2;
	for(i=1;i<=N;i++) {
		people[i].score = get();
		people[i].id = i;
	}
	for(i=1;i<=N;i++) {
		people[i].power = get();
	}
	sort(people+1, people+1+N, cmp);
	for(i=0;i<R;i++) {  //进行R此比赛 
		for(j=1;j<=N;j+=2) {
			if(people[j].power>people[j+1].power) 
				people[j].score++;
			else people[j+1].score++;
		}
		merge(1, 1+N);
	}
	cout<<people[Q].id;
	return 0;
}
