#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
#define Max(a,b) (a>b?a:b)
using namespace std;
const int MAXN = 200;
int pp[205], cnt=0, prime[35];
bool vis[205], t[105];

void Init() {
	int i, j;
	for(i=2;i<MAXN;i++) {
		if(!vis[i]) t[i] = true, pp[cnt++] = i;
		for(j=0;j<cnt && i*pp[j]<MAXN;j++) {
			vis[i*pp[j]] = true;
			if(i%pp[j]==0) break;
		}
	}
	cnt = 0;
	for(i=2;i<MAXN;i++) {
		if(t[i]) {
			prime[++cnt] = i;
			if(cnt>=29) break;
		}
	}
}

void Inverse(int *A, int length) {
	int mid = length>>1;
	for(int i=1;i<=mid;i++) {
		swap(A[i], A[length-i+1]);
	}
}

int main()
{
	Init();
	while(1) {
		int index1=0, index2=0, A[30], B[30];
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		char c;
		while(1) {
			scanf("%d%c", &A[++index1], &c);
			if(c==' ') break;
		}
		while(1) {
			scanf("%d%c", &B[++index2], &c);
			if(c=='\n') break;
		}
		if(index1==1 && index2==1 && A[1]==0 && B[1]==0) break;
		Inverse(A, index1);
		Inverse(B, index2);
		int len = Max(index1, index2);
		for(int i=1;i<=len;i++) {
			A[i] += B[i];
			A[i+1] += A[i]/prime[i];
			A[i] = A[i] % prime[i];
		}
		if(A[len+1]>0) len++;
		for(int i=len;i>=1;i--) {
			printf("%d%c", A[i], i==1?'\n':',');
		}
	}
	return 0;
}
