#include<iostream>
#include<cstdio>
#include<cstring>
#define res register int 
using namespace std;
int T, A[110], len;
char A1[110];

bool add() {  //找到最低位重复的数+1 
	res i, j, a;
	bool ok = 0;
	for(i=1;i<len;i++) {
		if(A[i]==A[i+1]) {
			A[i]++, ok=1;
			if(A[i]==10) a = 1;
			else a = 0;
			for(j=i-1;j>=1;j--) {
				A[j] = a;
				a = 1-a;
			}
		}
	}
	for(i=1;i<=len;i++) {
		if(A[i]>9) A[i]-=10, A[i+1]++;
	}
	if(A[len+1]>0) len++;
	return ok;
}

int main()
{
	scanf("%d", &T);
	int i, j;
	for(int kase=0;kase<T;kase++) {
		memset(A, 0, sizeof(A));
		scanf("%s", A1);
		len = strlen(A1);
		for(i=1;i<=len;i++) {
			A[i] = A1[len-i]^48;
		}
		if(!add()) {
			A[1]++;
			for(i=1;i<=len;i++) {
				if(A[i]>9) A[i]-=10, A[i+1]++;
			}
		}
		if(A[len+1]>0) len++;
		printf("case #%d:\n", kase);
		while(1) if(!add()) break;
		for(i=len;i>=1;i--) printf("%d", A[i]);
		putchar('\n');
	}
	return 0;
}
