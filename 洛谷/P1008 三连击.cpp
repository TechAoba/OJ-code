#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int A[10], i;
	for(i=1;i<=9;i++) {
		A[i] = i;
	}
	do{
		int a1 = A[1]*100+A[2]*10+A[3];
		int a2 = A[4]*100+A[5]*10+A[6];
		if(a1*2 != a2) continue;
		int a3 = A[7]*100+A[8]*10+A[9];
		if(a1*3 != a3) continue;
		cout<<a1<<" "<<a2<<" "<<a3<<endl;
	}while(next_permutation(A+1, A+10));
	return 0;
}
