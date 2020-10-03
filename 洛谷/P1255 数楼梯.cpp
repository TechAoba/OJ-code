#include<iostream>
#include<cstring>
#include<cstdio>
#define MAX(a,b) (a>b?a:b)
using namespace std;
char ans[5005][1500]; 

void reverse(char A[]) {
	char c;
	int length = strlen(A);
	int mid = length/2-1;
	for(int i=0;i<=mid;i++) {
		c = A[i], A[i] = A[length-i-1], A[length-i-1] = c;
	}
}

inline void init(int a) {
	for(int i=0;i<1500;i++) ans[a][i] = '\0';
}

int main()
{
	int i, j, a, b, c, N, len1, len2, len;
	cin>>N;
	if(N==0) {
		cout<<0;return 0;
	}
	init(0);ans[0][0]='1';
	init(1);ans[1][0]='1';
	for(i=2;i<=N;i++) {
		int lend = 0;  //½øÎ» 
		init(i);
		len1=strlen(ans[i-2]), len2=strlen(ans[i-1]);
		len = MAX(len1,len2);
		reverse(ans[i-2]);
		reverse(ans[i-1]);
		for(j=0;j<len;j++) {
			a = ans[i-2][j]=='\0'?0:ans[i-2][j]^48;
			b = ans[i-1][j]=='\0'?0:ans[i-1][j]^48;
			c = a+b+lend;
			ans[i][j] = (c%10)+'0';
			lend = c/10;
		}
		if(lend==1) ans[i][len] = '1', ans[i][len+1]='\0';
		else ans[i][len] = '\0';
		reverse(ans[i-2]);
		reverse(ans[i-1]);
		reverse(ans[i]);
	}
	printf("%s", ans[N]);
	return 0;
}
