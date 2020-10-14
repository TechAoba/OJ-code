#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int A[1005][25], N, ans[1005], Map[1005][1005];

void fun(int id) {
	int num = 0, quan=1;
	for(int i=0;i<25;i++) {
		if(A[id][i]&1) num+=quan;
		quan <<= 1;
	}
	ans[id] = num;
} 

void fun1(int a, int b, int val) {
	int poi = 0;
	while(val) {
		if(val&1) A[a][poi] = 1, A[b][poi] = 1;
		val>>=1;
		poi++;
	}
}

int main()
{
	scanf("%d", &N);
	int i, j;
	for(i=1;i<=N;i++) {
		for(j=1;j<=N;j++) {
			scanf("%d", &Map[i][j]);
			fun1(i, j, Map[i][j]);
		}
	}
	for(i=1;i<=N;i++) {
		fun(i);
		printf("%d%c", ans[i], i=='N'?'\n':' ');
	}
	return 0;
} 
