#include<iostream>
using namespace std;
const int MAXN = 40000+5;
int num[MAXN], N;

int main()
{
	int i, j, ans;
	cin>>N;
	if(N==1) {cout<<0; return 0;}
	N--;
	ans=N*N;
	for(i=N;i>1;i--) {
		num[i] = (N/i)*(N/i);
		for(j=i*2;j<=N;j+=i) num[i]-=num[j];
		ans-=num[i];
	}
	cout<<ans+2;
	return 0;
}
