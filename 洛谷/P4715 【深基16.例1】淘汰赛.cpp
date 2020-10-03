#include<iostream>
#include<cstdio>
#include<cstring>
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
using namespace std;
int A[129], dp[129][8], N, layer;

int main()
{
	int i, j;
	scanf("%d", &layer);
	N = 1<<layer;
	for(i=1;i<=N;i++) scanf("%d", &A[i]), dp[i][0]=i;
	if(layer==1) {
		printf("%d\n", A[1]>A[2]?2:1);
		return 0;
	}
	for(j=1;j<layer;j++) {
		for(i=1;i+(1<<j)-1<=N;i++) {
			dp[i][j] = A[dp[i][j-1]]>A[dp[i+(1<<(j-1))][j-1]]?dp[i][j-1]:dp[i+(1<<(j-1))][j-1];
		}
	}
	printf("%d\n", A[dp[1][layer-1]]<A[dp[1+(1<<(layer-1))][layer-1]]?dp[1][layer-1]:dp[1+(1<<(layer-1))][layer-1]);
	return 0;
 } 
