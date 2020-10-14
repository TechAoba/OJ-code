#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
LL A[35][35]; 

void product() {  //Éú³ÉÑî»ÔÈý½Ç 
	int i, j;
	for(i=1;i<=30;i++) {
		A[i][1] = A[i][i] = 1;
	}
	for(i=3;i<=30;i++) {
		for(j=2;j<i;j++) {
			A[i][j] = A[i-1][j-1] + A[i-1][j];
		}
	}
}

void print(int n) {
	int i, j;
	for(i=1;i<=n;i++) {
		for(j=1;j<=i;j++) {
			printf("%lld%c", A[i][j], i==j?'\n':' ');
		}
	}
}

int main()
{
	int k;
	bool flag = false;
	product();
	while(cin>>k && k!=0) {
		if(flag) cout<<endl;
		flag = true;
		print(k);
	}
	return 0;
}
