#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN = 100000+5;
int A[MAXN], dp1[MAXN], dp2[MAXN], ans1=1, ans2=1, cnt=1;

int main()
{
	while(scanf("%d", &A[cnt])!=EOF) cnt++;
	cnt--;
	dp1[1] = dp2[1] = A[1];
	int p;
	for(register int i=2;i<=cnt;i++) {
		if(dp1[ans1]>=A[i]) dp1[++ans1] = A[i];
		else {
			p = upper_bound(dp1+1, dp1+1+ans1, A[i], greater<int>())-dp1;
			dp1[p] = A[i];
		}
		if(dp2[ans2]<A[i]) dp2[++ans2] = A[i];
		else {
			p = lower_bound(dp2+1, dp2+1+ans2, A[i])-dp2;
			dp2[p] = A[i];
		}
	}
	printf("%d\n%d\n", ans1, ans2);
	return 0;
 } 
