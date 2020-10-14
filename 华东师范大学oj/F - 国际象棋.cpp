#include<iostream>
int A[3000]={1}, l=1;
using namespace std;

void mul(int num) {
	int i;
	for(i=0;i<l;i++) {
		A[i]*=num;
	}
	for(i=0;i<l;i++) {
		A[i+1] += A[i]/10;
		A[i] = A[i]%10;
	}
	while(A[l]) {
		A[l+1] += A[l]/10;
		A[l] = A[l]%10;
		l++;
	}
}

int main()
{
	int N, i;
	cin>>N;
	for(i=2;i<=N;i++) {
		mul(i);
	}
	for(i=l-1;i>=0;i--) cout<<A[i];
	return 0;
} 
