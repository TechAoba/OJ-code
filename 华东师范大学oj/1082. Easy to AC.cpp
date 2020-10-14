#include<iostream>
#include<cstdio>
using namespace std;
int jie[12];

int main()
{
	int i, n;
	jie[0] = jie[1] = 1;
	for(i=2;i<12;i++) jie[i] = jie[i-1]*i;
	int A[10];
	A[0] = 1;
	for(i=1;i<10;i++) {
		A[i] = A[i-1] + jie[i+1];
	}
	
	while(cin>>n && n>=0) {
		bool ok = false;
		for(i=0;i<10;i++) if(n==A[i]) ok = true;
		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
