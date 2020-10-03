#include<iostream>
#include<cstdio>
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
using namespace std;
const int INF = 0x3f3f3f3f;

int main()
{
	int L, N, i, val, Tmin = 0, Tmax = 0;
	cin>>L>>N;
	for(i=0;i<N;i++) {
		scanf("%d", &val);
		int da = Max(val, L+1-val);
		int xiao = Min(val, L+1-val);
		Tmax = Max(Tmax, da);
		Tmin = Max(Tmin, xiao);
	}
	cout<<Tmin<<" "<<Tmax;
	return 0;
}
