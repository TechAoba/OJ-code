#include<iostream>
#include<cstring>
#include<cstdio>
#define MAX(a,b) (a>b?a:b)
using namespace std;

void reverse(char A[]) {
	char c;
	int length = strlen(A);
	int mid = length/2-1;
	for(int i=0;i<=mid;i++) {
		c = A[i], A[i] = A[length-i-1], A[length-i-1] = c;
	}
}

int main()
{
	int i, a, b, c;
	int lend = 0;  //½øÎ» 
	char A[105], B[105], C[105];
	for(i=0;i<105;i++) A[i]=B[i]='\0';
	scanf("%s", A);
	scanf("%s", B); 
	int len1=strlen(A), len2=strlen(B);
	int len = MAX(len1,len2);
	reverse(A);
	reverse(B);
	for(i=0;i<len;i++) {
		a = A[i]=='\0'?0:A[i]^48;
		b = B[i]=='\0'?0:B[i]^48;
		c = a+b+lend;
		C[i] = (c%10)+'0';
		lend = c/10;
	}
	if(lend==1) C[len] = '1', C[len+1]='\0';
	else C[len] = '\0';
	reverse(C);
	printf("%s", C);
	return 0;
}
