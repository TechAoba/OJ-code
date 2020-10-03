#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 2e5+10;
char P[205][15], T[100], A[MAXN];
int dp[MAXN], Next[15];

void getNext(char *s, int len) {
	memset(Next, 0, sizeof(Next));
	int i=0,j=-1;
	Next[0] = -1;
	while(i<len) {
		if(j==-1 || s[i] == s[j]) Next[++i] = ++j;
		else j = Next[j]; //不匹配 
	}
}

void KMP(char *s, int len) {  //s在A串里面 
	int i=0, j=0, len1 = strlen(s);
	while(i<len) {
		if(j==-1 || A[i]==s[j]) {
			i++;j++;
		}
		else j = Next[j];
		if(j==len1) { //查找成功 
			dp[i]--;
			dp[i-len1]++;
			j = Next[j];
		}
	}
}

int main()
{
	int cnt = 0, n = 0, i;
	while(scanf("%s", P[cnt])) {
		if(P[cnt][0] == '.') break;
		cnt++;
	}
	while(scanf("%s", T) != EOF) {
		int len = strlen(T);
		for(i=0;i<len;i++) A[n++] = T[i];
	}
	for(i=0;i<cnt;i++) {  //遍历每一个模式串 
		int len = strlen(P[i]);
		getNext(P[i], len);  //得到Next数组
		KMP(P[i], n);
	}
	if(dp[0]==0) {
		printf("0\n");
		return 0;
	}
	for(i=1;i<n;i++) {
		dp[i] += dp[i-1];
		if(dp[i]==0) {
			printf("%d\n", i);
			return 0;
		}
	}
	//cout<<1;
	printf("%d\n", n);
	return 0;
}
