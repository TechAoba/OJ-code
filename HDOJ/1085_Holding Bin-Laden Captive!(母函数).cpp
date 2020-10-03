#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 8005;
int a, b, c, A[MAXN], B[MAXN];

int main()
{
	while(scanf("%d %d %d", &a, &b, &c) != EOF) {
		if(a==0 && b==0 && c==0) break;
		int i, j;
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		for(i=0;i<=a;i++) A[i] = 1;
		/*ѡ2Ԫ*/
		for(i=0;i<=a;i++) {
			for(j=0;j<=2*b;j+=2) {
				B[i+j] += A[i];
			}
		}
		memcpy(A, B, sizeof(B));
		memset(B, 0, sizeof(B));
		/*ѡ5Ԫ*/
		for(i=0;i<MAXN;i++) {
			for(j=0;j<=5*c && i+j<MAXN;j+=5) {
				B[i+j] += A[i];
			}
		}
		for(i=0;i<MAXN;i++) {
			if(!B[i]) {
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
 } 
