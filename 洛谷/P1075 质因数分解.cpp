#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN = 1e5; //只需要确定1e5的质数范围 
int pp[MAXN], cnt = 0;
bool vis[MAXN], prime[MAXN];

void Init() {
	for(int i=2;i<MAXN;i++) {
		if(!vis[i]) pp[cnt++] = i, prime[i] = true;
		for(int j=0;j<cnt && i*pp[j]<MAXN;j++) {
			vis[i*pp[j]] = true;
			if(i%pp[j]==0) break;
		} 
	}
}

bool isPrime(int a) {
	if(a<=1) return 0;
	if(a==2) return 1;
	int en = (int)sqrt(a+0.5);
	for(int i=2;i<=en;i++) if(a%i==0) return 0;
	return 1;
}

int main()
{
	Init();
	//cout<<prime[0]<<endl;
	int n, i;
	scanf("%d", &n);
	for(i=0;i<MAXN;i++) {
		if(prime[i] && n%i==0 && isPrime(n/i)) {
			printf("%d\n", n/i);
			return 0;
		}
	}
	return 0;
 } 
