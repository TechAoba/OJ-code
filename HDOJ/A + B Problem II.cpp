#include<iostream>
#include<cstdio>
#include<cstring>
#define Max(a,b) (a>b?a:b)
using namespace std;
int T, A[1005], B[1005], ans[1005];

void add() {
	memset(ans, 0, sizeof(ans));
	int len = Max(A[0], B[0]);
	for(int i=1;i<=len;i++) {
		ans[i] = A[i]+B[i];
	}
	for(int i=1;i<=len;i++) {
		ans[i+1] += ans[i]/10;
		ans[i] %= 10;
	}
	if(ans[len+1]!=0) len++;
	for(int i=len;i>=1;i--) {
		printf("%d", ans[i]);
	}
}

int main()
{
	char arr1[1005], arr2[1005];
	scanf("%d", &T);
	int i;
	for(int kase=1;kase<=T;kase++) {
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		scanf("%s %s", arr1, arr2);
		kase==1?printf("Case %d:\n", kase):printf("\nCase %d:\n", kase);
		printf("%s + %s = ", arr1, arr2);
		A[0] = strlen(arr1);
		B[0] = strlen(arr2);
		for(i=1;i<=A[0];i++) A[i] = arr1[A[0]-i] ^ 48;
		for(i=1;i<=B[0];i++) B[i] = arr2[B[0]-i] ^ 48;
		add();
		putchar('\n');
	}
	return 0;
}
