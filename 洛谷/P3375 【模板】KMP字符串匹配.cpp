#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 1000000+5;
int Next[MAXN], lenN, lenM;
char N[MAXN], M[MAXN];

void getNext() {
	Next[0] = -1;
	int i=0, j=-1;
	while(i<lenM) {
		if(j==-1||M[i]==M[j]) Next[++i] = ++j;
		else j = Next[j];
	}
}

void KMP() {
	int i=0, j=0;
	while(i<lenN) {
		if(j==-1 || N[i]==M[j]) {
			i++;j++;
		}
		else j = Next[j];
		if(j==lenM) {
			printf("%d\n", i-lenM+1);
			j = Next[j];
		}
	}
}

int main()
{
	scanf("%s %s", N, M);
	lenN = strlen(N);
	lenM = strlen(M);
	getNext();
	KMP();
	for(int i=1;i<=lenM;i++) {
		printf("%d ", Next[i]);
	}
	return 0;
 } 
