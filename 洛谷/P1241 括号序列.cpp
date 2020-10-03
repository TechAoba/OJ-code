#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char A[105], B[105];
int Q[105], top=0;

int main()
{
	int i, len;
	scanf("%s", A);
	len = strlen(A);
	for(i=0;i<len;i++) {
		if(A[i]=='(') Q[++top]=i, B[i]=')';
		else if(A[i]=='[') Q[++top]=i, B[i]=']';
		else if(A[i]==')') {  //右括号进行匹配 
			if(B[Q[top]] == ')') {  //匹配上了 
				B[Q[top--]] = ' ';  //出栈 
			}
			else B[i] = '(';
		}
		else if(A[i]==']') {
			if(B[Q[top]] == ']') {  //匹配上了 
				B[Q[top--]] = ' ';  //出栈 
			}
			else B[i] = '[';
		}
	}
	for(i=0;i<len;i++) {
		if(B[i]=='(' || B[i]=='[') putchar(B[i]);
		putchar(A[i]);
		if(B[i]==')' || B[i]==']') putchar(B[i]);
	}
	return 0;
}
