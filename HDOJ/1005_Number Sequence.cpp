#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int F[60], A, B, N;

int main()
{
	F[1] = F[2] = 1;
	while(scanf("%d %d %d", &A, &B, &N)==3 && (A|B|N)) {
		int i, j;
		for(i=3;i<55;i++)  {  //在这之间一定存在环 
			F[i] = (A * F[i-1] + B * F[i-2]) % 7;
		}
		if(N<55) {
			printf("%d\n", F[N]);
			continue;
		}
		bool find = false;
		for(i=3;i<55;i++) {
			for(j=2;j<i;j++) {
				if(F[i]==F[j] && F[i-1]==F[j-1]) { //找到了 
					find = 1;
					break;
				}
			}
			if(find) break;
		}
		printf("%d\n", F[j+(N-j)%(i-j)]);
	}
	return 0;
}
