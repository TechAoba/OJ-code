#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 100000+5;
int T, N, A[MAXN];

int main()
{
	scanf("%d", &T);
	for(int kase=1;kase<=T;kase++) {
		scanf("%d", &N);
		for(int i=1;i<=N;i++) scanf("%d", &A[i]);
		kase==1?printf("Case %d:\n", kase):printf("\nCase %d:\n", kase);
		int ans_start = 1, ans_max=A[1], ans_end=1;
		int now_start = 1;
		for(int i=1;i<=N;i++) {
			if(A[i-1] < 0) {
				now_start = i;  //区间的开始可能会发生改变 
			}
			else {
				A[i] += A[i-1];
			}
			if(A[i] > ans_max) {
				ans_start = now_start;
				ans_end = i;
				ans_max = A[i];
			}
		}
		printf("%d %d %d\n", ans_max, ans_start, ans_end);
	}
	return 0;
}

