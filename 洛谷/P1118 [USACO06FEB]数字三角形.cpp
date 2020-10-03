#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int Cmn(int m, int n) {  //m>n
	int mul = 1, i;
	for(i=m;i>=m-n+1;i--) mul*=i;
	for(i=2;i<=n;i++) mul/=i;
	return mul;
}

bool cmp(int a, int b) {
	return a>b;
}

int main()
{
	int N, sum, i, j, A[20], mul[20];
	cin>>N>>sum;
	for(i=1;i<=N;i++) {
		A[i] = i;
		mul[i] = Cmn(N-1, i-1);
	}
	do{
		int add = 0;
		for(j=1;j<=N;j++) {
			add += mul[j] * A[j];
			if(add>sum) {
				sort(A+j, A+N+1, cmp);
				break;
			}
		}
		if(add == sum) {
			for(j=1;j<=N;j++) printf("%d%c", A[j], j==N?'\n':' ');
			break;
		}
	}while(next_permutation(A+1, A+N+1));
	return 0;
}
