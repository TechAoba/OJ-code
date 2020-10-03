#include<iostream>
#define LL long long
using namespace std;
bool W[11];

int main()
{
	int k, N, wei=0;
	LL ans=0, add=1;
	cin>>k>>N;
	while(N) {
		if(N&1) W[wei] = true;
		N>>=1;
		wei++;
	}
	for(int i=0;i<11;i++) {
		if(W[i]) ans+=add;
		add*=k;
	}
	cout<<ans;
	return 0;
} 
