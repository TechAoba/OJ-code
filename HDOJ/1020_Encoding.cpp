#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 10000+5;
int N, id;
char A[MAXN];

struct Node{
	char ch;
	int num;
}node[MAXN];

int main()
{
	int i;
	scanf("%d", &N);
	while(N--) {
		scanf("%s", A+1);
		id = 0;
		int cnt = 0, len = strlen(A+1);
		char now = 't';  //不存在
		for(i=1;i<=len;i++) {
			if(A[i] != now) {  //变了 
				node[id].ch = now;
				node[id++].num = cnt;
				now = A[i];
				cnt = 1;
			}
			else {
				cnt++;
			}
		}
		node[id].ch = now;
		node[id++].num = cnt;
		for(i=1;i<id;i++) {
			if(node[i].num>1) printf("%d", node[i].num);
			printf("%c", node[i].ch);
		}
		printf("\n");
	}
	return 0;
}
