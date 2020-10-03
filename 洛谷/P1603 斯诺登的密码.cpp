#include<iostream>
#include<string>
#include<cstdio>
#include<queue>
using namespace std;
int A[30];
string S[30] = {
	"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", 
	"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", 
	"eighteen", "nineteen", "twenty", "a", "both", "another", "first", "second", "third"
};
priority_queue<int, vector<int>, greater<int> > Q;
void add(string s) {
	for(int i=1;i<27;i++) {
		if(S[i] == s) Q.push(A[i]);
	}
}

int main()
{
	int i;
	for(i=1;i<=20;i++) {
		A[i] = (i*i)%100;
	}
	A[21] = 1, A[22] = 4, A[23] = 1, A[24] = 1, A[25] = 4, A[26] = 9;
	string s;
	while(cin>>s && s!=".") {
		add(s);
	}
	bool flag = false;
	while(!Q.empty()) {
		int tmp = Q.top(); Q.pop();
		if(!flag) {
			if(tmp) printf("%d", tmp);
			flag = true;
		}
		else {
			printf("%02d", tmp);
		}
	}
	if(!flag) printf("0");
	return 0;
}
