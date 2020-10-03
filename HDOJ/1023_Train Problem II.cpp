#include<iostream>
#include<cstdio>
#include<cstring>
#define Max(a,b) (a>b?a:b)
using namespace std;
int A[105][105], N, T[105];

void show(int N) {
	for(int i=A[N][0];i>=1;i--) printf("%d", A[N][i]);
	printf("\n");
}

void showT() {
	for(int k=T[0];k>=1;k--) printf("%d", T[k]);
	printf("\n");
} 

inline void mul(int a, int b) {  //把a和b的乘积给T 
	memset(T, 0, sizeof(T));
	int i, j;
	for(i=1;i<=A[a][0];i++) {
		for(j=1;j<=A[b][0];j++) {
			T[i+j-1] += A[a][i] * A[b][j];
		}
	}
	T[0] = A[a][0] + A[b][0];
	for(i=1;i<=T[0];i++) T[i+1] += T[i]/10, T[i] %= 10;
	if(T[T[0]]==0) T[0]--;
	//printf("%d和%d相乘,得到的结果为:", a, b);
	//showT();
}

inline void add(int a) {  //A[a] + T
	int len = Max(A[a][0], T[0]);
	int i;
	for(i=1;i<=len;i++) {
		A[a][i] += T[i];
		A[a][i+1] += A[a][i] / 10;
		A[a][i] %= 10;
	}
	A[a][0] = len;
	if(A[a][len+1] > 0) A[a][0]++;
	//printf("开始len为%d, A[a][len+1] = %d, ", len, A[a][len+1]);
	//printf("相加后的结果为");
	//show(a);
}

int main()
{
	memset(A, 0, sizeof(A));
	int i, j;
	A[0][0] = A[0][1] = 1;
	A[1][0] = A[1][1] = 1;
	for(i=2;i<101;i++) {
		for(j=0;j<i;j++) {
			mul(j, i-j-1);
			add(i);
		}
		//printf("%d -> %d\n", i, A[i][0]);
	}
	while(scanf("%d", &N) != EOF) {
		show(N);
	}
	return 0;
}
