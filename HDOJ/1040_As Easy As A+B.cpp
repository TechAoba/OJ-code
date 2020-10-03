#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T, N, A[1005];

int main()
{
	cin>>T;
	while(T--) {
		scanf("%d", &N);
		int i;
		for(i=0;i<N;i++) scanf("%d", &A[i]);
		sort(A, A+N);
		for(i=0;i<N;i++) printf("%d%c", A[i], i==N-1?'\n':' ');
	}
	return 0;
}
