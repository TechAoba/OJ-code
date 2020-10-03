#include<iostream>
#include<stack>
#include<cstring>
#include<cstdio> 
using namespace std;
stack<char> S;

int main()
{
	char A[50];
	bool flag = true;
	int i = 0;
	scanf("%s", A);
	if(A[0]=='-') flag = false, i++;
	for(;i<strlen(A);i++) {
		//cout<<"A的长度为"<<strlen(A)<<endl;
		S.push(A[i]);
	}
	if(!flag) putchar('-');
	bool ok = false;
	while(!S.empty()) {
		if(S.top() != '0') ok = true;
		if(ok == true) printf("%c", S.top());
		S.pop();
	}
	return 0;
}
