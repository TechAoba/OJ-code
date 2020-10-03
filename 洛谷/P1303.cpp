#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int i, j, len=0;
	bool flag = 1;  //Õý 
	char A1[2010], B1[2010];
	int A[2010], B[2010], ans[5000];
	scanf("%s %s", A1, B1);
	if(A1[0]=='-') {  //
		flag = 1-flag;
		A[0] = strlen(A1)-1;
		for(i=1;i<=A[0];i++) A[i] = A1[A[0]-i+1]^48;
	}
	else {
		A[0] = strlen(A1);
		for(i=1;i<=A[0];i++) A[i] = A1[A[0]-i]^48;
	}
	
	if(B1[0]=='-') {  //
		flag = 1-flag;
		B[0] = strlen(B1)-1;
		for(i=1;i<=B[0];i++) B[i] = B1[B[0]-i+1]^48;
	}
	else {
		B[0] = strlen(B1);
		for(i=1;i<=B[0];i++) B[i] = B1[B[0]-i]^48;
	}
	/*for(i=B[0];i>=1;i--) printf("%d", B[i]);
	cout<<endl;*/
	len = A[0] + B[0];
	for(i=1;i<=A[0];i++) {
		for(j=1;j<=B[0];j++) {
			ans[i+j-1] += A[i]*B[j];
		}
	}
	for(i=1;i<len;i++) if(ans[i]>9) ans[i+1]+=ans[i]/10, ans[i]%=10;  //½øÎ» 
	while(ans[len]==0 && len>1) len--;
	if(!flag) putchar('-');
	for(i=len;i>=1;i--) printf("%d", ans[i]);
	return 0;
}
