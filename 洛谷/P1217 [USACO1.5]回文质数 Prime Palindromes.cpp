#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 10000005;
bool prime[MAXN], vis[MAXN];
int pp[MAXN];

bool hui(int num) {
	int t = 0, a = num;
	while(a) {
		t = t*10 + a%10;
		a/=10;
	}
	if(t==num) return true;
	return false;
}

int main()
{
	int i, j, st, en, cnt = 0;
	scanf("%d %d", &st, &en);
	if(en>10000000) en = 10000000;
	for(i=2;i<=en;i++) {
		if(!vis[i]) prime[i] = true, pp[cnt++] = i;  //pp为基础质数 
		for(j=0;j<cnt && i*pp[j]<=en;j++) {  //j循环基础质数 
			vis[i*pp[j]] = true;
			if(i%pp[j]==0) break;
		} 
	}
	if(st%2==0) st++;
	for(;st<=en;st+=2) {
		if(st>10000000) break;
		if(prime[st] && hui(st)) printf("%d\n", st);
	}
	return 0;
 } 
