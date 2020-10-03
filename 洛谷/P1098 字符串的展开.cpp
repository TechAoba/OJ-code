#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;
int p1, p2, p3;
char A[105];

inline bool is1(char c) {
	if(c>='0' && c<='9') return true;
	return false;
}

inline bool is2(char c) {
	if(c>='a' && c<='z') return true;
	return false;
}

int main()
{
	cin>>p1>>p2>>p3;
	scanf("%s", A);
	int i, j, k, len = strlen(A);
	char st, en;
	for(i=0;i<len;i++) {
		if(A[i]!='-') printf("%c", A[i]);
		else {
			st = A[i-1]+1, en = A[i+1]-1;
			if(st == en+1) continue;
			else if((is1(st)&&is1(en) || is2(st)&&is2(en)) && st<=en) {
				if(p3==1) {  //ÕýÐò 
					for(j=st;j<=en;j++) {
						for(k=1;k<=p2;k++) {
							if(p1==1) printf("%c", j);
							else if(p1==2) {
								if(is2(j)) printf("%c", j-32);
								else printf("%c", j);
							}
							else if(p1==3) printf("*");
						}
					}
				}
				else {
					for(j=en;j>=st;j--) {
						for(k=1;k<=p2;k++) {
							if(p1==1) printf("%c", j);
							else if(p1==2) {
								if(is2(j)) printf("%c", j-32);
								else printf("%c", j);
							}
							else if(p1==3) printf("*");
						}
					}
				}
			}
			else printf("-");
		}
	}
	return 0;
 } 
