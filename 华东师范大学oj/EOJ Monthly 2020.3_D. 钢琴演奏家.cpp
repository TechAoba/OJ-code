#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define res register int
#define LL long long
using namespace std;
const LL MOD = 1e9+7;
const int MAXN = 1000005;
LL T, N, M, F[MAXN], I[MAXN], A[MAXN];

inline LL mul(LL a, LL b) {  //¿ìËÙ³Ë 
	LL ans = 0;
	while(b) {
		if(b&1) ans = (ans+a)%MOD;
		b>>=1;
		a = (a+a)%MOD;
	}
	return ans;
}

inline LL read() {
	LL x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

inline LL pow(LL a, LL b) {
	LL ans = 1;
	while(b) {
		if(b&1) ans = mul(ans, a);
		b >>= 1;
		a = mul(a, a);
	}
	return ans;
}

void Init() {
	F[0] = 1;
	res i;
	for(i=1;i<MAXN;i++) {
		F[i] = mul(F[i-1], i);
		//printf("%d %lld\n", i, F[i]);
	}
	I[1000000] = pow(F[1000000], MOD-2);
	for(i=1000000-1;i;i--) {
		I[i] = mul(I[i+1], i+1);
	}
}

inline LL C(LL a, LL b) {
	if(a==b || b==0) return 1;
	return mul(F[a], mul(I[b], I[a-b]));
}

int main()
{
	Init();
	//printf("%lld\n", F[10]);
	T = read();
	while(T--) {
		LL ans = 0, sum=0;
		N = read(), M= read(); 
		LL i; 
		for(i=1;i<=N;i++) A[i] = read(), sum = (sum+A[i])%MOD;
		sort(A+1, A+N+1);
		for(i=M;i<=N;i++) {
			ans=(ans+mul(A[i], C(i-1, M-1)))%MOD;
			//printf("C %lld %lld %lld\n", i-1, M-1, C(i-1, M-1));
		}
		if(M==1) printf("%lld\n", sum);
		else printf("%lld\n", ans);
	}
	return 0;
 } 
