#include<iostream>
#include<cstdio>
#include<cstring>
#define Max(a,b) (a>b?a:b)
#define LL long long
using namespace std;
int A[5005], N;
LL num[5005], way[5005], len=0, ans=0;  //num代表最长长度  way代表方案数 

int main()
{
	int i, j;
	scanf("%d", &N);
	for(i=1;i<=N;i++) {
		scanf("%d", &A[i]);
		num[i] = 1; way[i] = 0;
	}
	for(i=1;i<=N;i++) {
		for(j=1;j<i;j++) {
			if(A[j]>A[i]) num[i] = Max(num[i], num[j]+1);
		}
		len = Max(len, num[i]);
	}
	for(i=1;i<=N;i++) {
		if(num[i]==1) way[i] = 1;
		for(j=1;j<i;j++) {
			if(num[j]+1==num[i] && A[i]<A[j]) way[i]+=way[j];
			else if(num[i]==num[j] && A[i]==A[j]) way[i]=0;
		}
		if(num[i]==len) ans+=way[i]; 
	}
	//for(i=1;i<=N;i++) cout<<num[i]<<"  "<<way[i]<<endl;
	cout<<len<<" "<<ans<<endl;
	return 0;
}
