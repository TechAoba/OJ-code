#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 1000005;
int A[MAXN], N, M;

inline int find(int a) {
	int left = 1, right = N, mid;
	while(left<=right) {
		//printf("%d\n", mid);
		mid = (left+right)>>1;
		if(A[mid]==a) return mid;
		else if(A[mid]>a) right=mid-1;
		else left = mid+1;
	}
	return -1;
}

int main()
{
	scanf("%d %d", &N, &M);
	int i, a;
	for(i=1;i<=N;i++) scanf("%d", &A[i]);
	for(i=0;i<M;i++) {
		scanf("%d", &a);
		int poi = lower_bound(A+1, A+1+N, a)-A;
		if(A[poi] != a) printf("-1 ");
		else printf("%d ", poi);
	}
	return 0;
}
