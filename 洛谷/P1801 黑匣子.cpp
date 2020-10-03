#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN = 200005;
int A[MAXN];

priority_queue<int> Q;
priority_queue<int, vector<int>, greater<int> > Q1;

int main()
{
	int N, M, i, j, l=1, r, num;
	scanf("%d %d", &N, &M);
	for(i=1;i<=N;i++) scanf("%d", &A[i]);
	for(num=1;num<=M;num++) {
		scanf("%d", &r);
		for(j=l;j<=r;j++) {
			Q.push(A[j]);
			if(Q.size()==num) Q1.push(Q.top()), Q.pop();
		}
		l = r+1;
		printf("%d\n", Q1.top());
		Q.push(Q1.top()), Q1.pop();
	}
	return 0;
}
