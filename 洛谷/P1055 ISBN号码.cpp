#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	char A[15];
	scanf("%s", A);
	int i, ans = (A[0]-'0')+(A[2]-'0')*2+(A[3]-'0')*3+(A[4]-'0')*4+(A[6]-'0')*5;
	ans += (A[7]-'0')*6+(A[8]-'0')*7+(A[9]-'0')*8+(A[10]-'0')*9;
	ans %= 11;
	if(ans==10 && A[12]=='X') cout<<"Right";
	else if(ans+'0' == A[12]) cout<<"Right";
	else {
		for(i=0;i<12;i++) printf("%c", A[i]);
		if(ans==10) printf("X");
		else printf("%d", ans);
	}
	return 0;
}
