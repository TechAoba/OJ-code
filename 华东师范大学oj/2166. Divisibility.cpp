#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 10000+5, MOD = 61;
int quan[MAXN], A[MAXN];

inline int to(char c) {
	if(c>='0' && c<='9') return c^48;
	if(c>='A' && c<='Z') return c-'A'+10;
	if(c>='a' && c<='z') return c-'a'+36;
}

inline int mul(int a, int b) {
	int ans = 0;
	while(b) {
		if(b&1) ans = (ans+a) % MOD;
		a = (a+a) % MOD;
		b >>= 1;
	}
	return ans;
}

void Init() {
	quan[1] = 1;
	for(register int i=2;i<MAXN;i++) {
		quan[i] = mul(quan[i-1], 62);
	}
}

int main()
{
	Init();
	register int i;
	char s[MAXN];
	while(scanf("%s", s) != EOF) {
		if(strcmp(s, "end")==0) break;
		memset(A, 0, sizeof(A));
		int len = strlen(s);
		for(i=1;i<=len;i++) A[i] = to(s[len-i]);
		int sum = 0;
		for(i=1;i<=len;i++) {
			sum = (sum + mul(A[i], quan[i])) % MOD;
		}
		if(!sum) printf("yes\n");
		else printf("no\n");
	}
	return 0;
 } 
