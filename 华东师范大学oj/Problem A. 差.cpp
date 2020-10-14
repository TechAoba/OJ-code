#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int A[3] = {1, 0, 0}, B[3] = {0, 1, 0}, C[3] = {0, 0, 1};
	int Ta[3], Tb[3], Tc[3];
	for(int i=1;i<=30;i++) {
		printf("Case %d: %dA+%dB+%dC   ", i, A[0], B[0], C[0]);
		printf("%dA+%dB+%dC   ", A[1], B[1], C[1]);
		printf("%dA+%dB+%dC   ", A[2], B[2], C[2]);
		printf("²îÎª %dA+%dB+%dC\n", A[0]-A[1], B[0]-B[1], C[0]-C[1]);
		memcpy(Ta, A, sizeof(int)*3);
		memcpy(Tb, B, sizeof(int)*3);
		memcpy(Tc, C, sizeof(int)*3);
		A[0] = Tb[0]+Tc[0];
		A[1] = Tb[1]+Tc[1];
		A[2] = Tb[2]+Tc[2];
		
		B[0] = Ta[0]+Tc[0];
		B[1] = Ta[1]+Tc[1];
		B[2] = Ta[2]+Tc[2];
		
		C[0] = Tb[0]+Ta[0];
		C[1] = Tb[1]+Ta[1];
		C[2] = Tb[2]+Ta[2];
	}
	return 0;
}
