#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
unsigned int a;
int p, len, st, en, A[32];

inline bool in(int a) {
	if(a>=st && a<=en) return 1;
	return 0;
}

int main()
{
	cin>>a>>p>>len;
	st = p-len+1, en=p;
	unsigned int ans=0, quan=1, i;
	for(i=0;i<32;i++) {
		if(a&1) A[i] = 1;
		if(in(i)) A[i] = 1-A[i];
		if(A[i]) ans += quan;
		quan *= 2;
		a >>= 1;
	}
	printf("%u\n", ans);
	return 0;
 } 
