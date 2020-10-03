#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int A[100005], T[100005], L;
char s[100005];

inline void add(int a) {
	T[1] += a;
	int i;
	for(i=1;i<=L;i++) T[i+1] += T[i]/10, T[i] %= 10;
	if(T[L+1]!=0) L++;  //长度加一
}

int main()
{
	int i;
	while(scanf("%s", s) != EOF) {
		if(strcmp("0", s) == 0) break;
		memset(A, 0, sizeof(A));
		A[0] = strlen(s);  //长度 
		for(i=0;i<A[0];i++) A[A[0]-i] = s[i]^48;
		while(A[0] != 1) {
			L = 1;
			memset(T, 0, sizeof(T));
			for(i=1;i<=A[0];i++) add(A[i]);
			memcpy(A, T, sizeof(T)); 
			A[0] = L;
		}
		printf("%d\n", A[1]);
	}
	return 0;
}
