#include<iostream>
#include<cstring>
#define Max(a,b) (a>b?a:b)
using namespace std;
char A1[1005], B1[1005];
int A[1005], B[1005];

int main()
{
	int i, Tmax, ans;
	while(scanf("%s %s", A1, B1)) {
		if(A1[0]=='0' && B1[0]=='0') break;
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		A[0] = strlen(A1), B[0] = strlen(B1);
		for(i=1;i<=A[0];i++) A[i] = A1[A[0]-i]^48;
		for(i=1;i<=B[0];i++) B[i] = B1[B[0]-i]^48;
		Tmax = Max(A[0], B[0]);
		ans = 0;
		for(i=1;i<=Tmax;i++) {
			A[i] += B[i];
			if(A[i]>9) {
				ans++;
				A[i] -= 10;
				A[i+1]++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
 } 
