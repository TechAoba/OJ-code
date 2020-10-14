#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;

int main()
{
	int i, cnt=0, N, a, b;
	string S;
	getline(cin,S);
	int len = S.length();
	for(i=0;i<len;i++) {
		if(S[i]=='a' && S[i+1]=='p' && S[i+2]=='p' && S[i+3]=='l' && S[i+4]=='e') {
			printf("peach");
			i += 4;
			continue;
		}
		else if(S[i]=='p' && S[i+1]=='e' && S[i+2]=='a' && S[i+3]=='c' && S[i+4]=='h') {
			printf("apple");
			i += 4;
			continue;
		}
		printf("%c", S[i]);
	}
	cout<<endl;
	return 0;
 } 
