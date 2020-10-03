#include<iostream>
#include<cstdio>
#include<cstring>
#define Max(a,b) (a>b?a:b)
using namespace std;
int ans[500], add[500], len, len1=0;

void cal(int num) {  //给add乘上num 
	int up = 0, cur = 0;
	while(true) {
		int Temp = add[cur]*num+up;
		add[cur++] = Temp%10;
		up = Temp / 10;
		if(cur>=len && up==0) break;
	}
	len = cur;
}

void jie(int num) {  //计算num的阶乘  再加给ans 
	memset(add, 0, sizeof(add));
	add[0] = 1; len = 1;
	int i;
	for(i=2;i<=num;i++) {
		cal(i);
	}
	int T = Max(len, len1), up = 0;
	for(i=0;i<=T;i++) {
		int tmp = ans[i] + add[i] + up;
		ans[i] = tmp%10;
		up = tmp / 10;
	}
	ans[T]==0?len1=T:len1=T+1;
}

int main()
{
	int N;
	while(cin>>N) {
		len1 = 0;
		memset(ans, 0, sizeof(ans));
		int i;
		for(i=1;i<=N;i++) {
			jie(i);
		}
		for(i=len1-1;i>=0;i--) {
			printf("%d", ans[i]);
		}
		putchar('\n');	
	}
	
	return 0;
}
