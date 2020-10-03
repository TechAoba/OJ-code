#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char A[100];

int main()
{
	int move, i;
	cin>>move;
	scanf("%s", A);
	for(i=0;i<strlen(A);i++) {
		int tmp = A[i]-'a';
		tmp += move;
		tmp %= 26;
		A[i] = tmp+'a';
	}
	printf("%s", A);
	return 0;
}
