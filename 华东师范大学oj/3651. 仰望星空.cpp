#include<iostream>
#define LL long long
using namespace std;

int main()
{
	LL N, A, B, Mi, Ma;
	cin>>N>>A>>B;
	Ma = B*N-(B-A);
	Mi = A*N+(B-A);
	cout<<Ma-Mi+1;
	return 0;
}
