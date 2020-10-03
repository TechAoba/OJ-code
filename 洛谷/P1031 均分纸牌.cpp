#include<iostream>
#include<cstdio>
using namespace std;
int A[105], B[105];

int main()
{
	int N, i, ave=0, sum=0, ans=0;
	scanf("%d", &N);
	for(i=1;i<=N;i++) {
		scanf("%d", &A[i]);
		ave += A[i];
	}
	ave/=N;
	//cout<<ave;
	for(i=1;i<=N;i++) {
		sum+=A[i];
		B[i] = sum-i*ave;
	}
	for(i=1;i<=N;i++) if(B[i]) ans++;
	cout<<ans<<endl;
	return 0;
 } 
