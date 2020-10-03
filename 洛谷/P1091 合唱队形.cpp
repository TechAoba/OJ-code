#include<iostream>
#include<cstring>
#define Max(a,b) (a>b?a:b)
using namespace std;
int A[105], Asc[105], Dec[105];

int main()
{
	int i, j, N, ans = 0;
	cin>>N;
	for(i=1;i<=N;i++) {
		Dec[i]=Asc[i]=1;
		cin>>A[i];
		for(j=1;j<i;j++) {
			if(A[j]<A[i]) Asc[i] = Max(Asc[i], Asc[j]+1);
			//else if(A[j]>A[i]) Dec[i] = Max(Dec[i], Dec[j]+1);
		}
	} 
	for(i=N;i>=1;i--) {
		for(j=N;j>i;j--) {
			if(A[j]<A[i]) Dec[i] = Max(Dec[i], Dec[j]+1);
		}
	}
	/*for(i=1;i<=N;i++) {
		cout<<"第"<<i<<"位同学升序"<<Asc[i]<<endl; 
	}*/
	for(i=1;i<=N;i++) ans = Max(ans, Dec[i]+Asc[i]-1);
	cout<<N-ans<<endl;
	return 0;
 } 
