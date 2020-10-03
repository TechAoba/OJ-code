#include<iostream>
#include<stack>
#include<cctype>
#include<cstring>
#include<cstdio>
using namespace std;
char A[2000];
stack <int> S;

int main()
{
	scanf("%s", A);
	int i, j, len = strlen(A);
	for(i=0;i<len;i++) {
		if(A[i]=='@') break;
		if(A[i] == '.') continue;
		else if(isdigit(A[i])) {
			int num = 0;
			for(j=i;;j++) {
				if(A[j]=='.') break;
				num = 10*num+A[j]-'0';
			}
			S.push(num);
			i=j;
		}
		else if(A[i]=='+' || A[i]=='-' || A[i]=='*' || A[i]=='/') {
			int t2 = S.top(); S.pop();
			int t1 = S.top(); S.pop();
			if(A[i]=='+') {
				S.push(t1+t2);
			}
			else if(A[i]=='-') {
				S.push(t1-t2);
			}
			else if(A[i]=='*') {
				S.push(t1*t2);
			}
			else if(A[i]=='/') {
				S.push(t1/t2);
			}
		}
	}
	cout<<S.top();
	return 0;
} 
