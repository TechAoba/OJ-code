#include<iostream>
#include<cstring>
using namespace std;
const int MAXN = 100005;
char A[MAXN], B[MAXN];

int main()
{
	int i, j;
	while(scanf("%s %s", A, B) != EOF) {
		int len1 = strlen(A), len2 = strlen(B);
		j=0;
		bool ok = 0;
		for(i=0;i<len2;i++) {
			if(A[j]==B[i]) {
				j++;
				if(j==len1) {
					ok=1;
					break;
				}
			}
		}
		if(ok) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
