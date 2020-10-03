#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

inline bool yuan(char ch) {
	if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return true;
	return false;
}

inline bool accept(char *s) {
	int len = strlen(s), i, j;
	/*包含元音*/
	bool have = false;
	for(i=0;i<len;i++) {
		if(yuan(s[i])) {
			have = true;
			break;
		}
	}
	if(!have) return false;
	/*不包含三个连续的元音或辅音*/
	for(i=0;i<len;i++) {
		bool flag = yuan(s[i]);
		for(j=i+1;j<len;j++) {
			if(flag != yuan(s[j])) break;
		}
		if(j-i>2) return false;
		i = j-1;
	}
	/*不包含连续相同*/
	for(i=1;i<len;i++) if(s[i]==s[i-1] && s[i]!='o' && s[i]!='e') return false;
	return true;
}

int main()
{
	char s[100005];
	while(scanf("%s", s) != EOF) {
		if(strcmp("end", s) == 0) break;
		if(accept(s)) {
			printf("<%s> is acceptable.\n", s);
		}
		else {
			printf("<%s> is not acceptable.\n", s);
		}
	}
	return 0;
} 
