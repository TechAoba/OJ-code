#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char A[10], B[10];

int main()
{
	scanf("%s %s", A, B);
	int i, val1=1, val2=1, len1 = strlen(A), len2 = strlen(B);
	for(i=0;i<len1;i++) {
		val1 = val1*(A[i]-'A'+1)%47;
	}
	for(i=0;i<len2;i++) {
		val2 = val2*(B[i]-'A'+1)%47;
	}
	if(val1==val2) cout<<"GO";
	else cout<<"STAY";
	return 0;
}
