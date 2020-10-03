#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
void create(string s) {
	int len = s.length();
	if(len==1) {
		if(s[0]=='1') putchar('I');
		else putchar('B');
		return;
	}
	int B=0, I=0, mid = len/2;
	create(s.substr(0, mid)); create(s.substr(mid));
	for(int i=0;i<len;i++) {
		if(s[i]=='1') I=1;
		else B=1;
	}
	if(I&&B) putchar('F');
	else if(I) putchar('I');
	else putchar('B');
}

int main()
{
	int N;
	string s;
	cin>>N>>s;
	create(s);
	return 0;
}
