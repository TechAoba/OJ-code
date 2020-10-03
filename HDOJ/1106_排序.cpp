#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int A[1005];
char s[1005];

void solve() {
	memset(A, 0, sizeof(A));
	int id = 1, len = strlen(s), i;
	bool have = false;
	for(i=0;i<len;i++) {
		if(s[i]!='5') {
			if(i>0 && s[i-1]=='5') id++;
			A[id] = A[id]*10+(s[i]^48);
		}
	}
	sort(A+1, A+1+id);
	i=1;
	if(s[0]=='5') i++;
	for(;i<=id;i++) printf("%d%c", A[i], i==id?'\n':' ');
}

int main()
{
	while(scanf("%s", s)!=EOF) {
		solve();
	}
	return 0;
}
