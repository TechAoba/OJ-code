#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define res register int
#define LL long long
using namespace std;
const int MAXN = 1e6+10;
int A[MAXN], B[MAXN], N;

inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

bool cmp(int a, int b) {
	return a>b;
}

int main()
{
	N = read();
	res i;
	LL ans=0;
	for(i=0;i<N;i++) A[i] = read();
	for(i=0;i<N;i++) B[i] = read();
	sort(A, A+N), sort(B, B+N);
	int k=0;
	vector<int> V;
	for(i=1;i<N;i++) {
		if(A[i]<=A[i-1]) {
			V.push_back(A[i-1]-A[i]+1);
			A[i] = A[i-1]+1;
		}
	}
	sort(V.begin(), V.end(), cmp);
	for(i=0;i<V.size();i++) {
		ans += V[i] * B[k++];
	}
	printf("%lld\n", ans);
	return 0;
}
