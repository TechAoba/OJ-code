#include<iostream>
#include<string>
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
using namespace std;
int Tmax=-0x3f3f3f3f, Tmin=0x3f3f3f3f;

int main()
{
	int i, N, a;
	cin>>N;
	for(i=0;i<N;i++) {
		cin>>a;
		Tmax = Max(Tmax, a);
		Tmin = Min(Tmin, a);
	}
	cout<<Tmax-Tmin<<endl;
	return 0;
}
