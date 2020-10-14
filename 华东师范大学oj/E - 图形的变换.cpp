#include<iostream>
#define Min(a,b) (a<b?a:b)
using namespace std;
int N, M, A[5], i, ans=0;

int main()
{
	cin>>N>>M;
	A[1]=A[2]=A[3]=M,i=1;
	while(A[1]<N || A[2]<N || A[3]<N) {
		A[i] = Min(A[1]+A[2]+A[3]-A[i]-1, N);
		i++;
		if(i==4) i = 1;
		ans++;
	}
	cout<<ans;
	return 0;
}
