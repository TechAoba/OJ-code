#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
int N;
char s1[15], s2[15];
int A[15], B[15];
bool inStack[15];

int main()
{
	while(scanf("%d", &N) != EOF) {
		int oper[30], step=0;
		stack<int> Stack;
		memset(inStack, 0, sizeof(inStack));
		scanf("%s %s", s1+1, s2+1);
		int i, j=1;
		for(i=1;i<=N;i++) A[i]=s1[i]^48, B[i]=s2[i]^48;
		bool ok = 1;
		for(i=1;i<=N;i++) {
			if(!inStack[B[i]]) {  //入栈 
				for(;j<=N;j++) {
					Stack.push(A[j]);
					inStack[A[j]] = 1;
					oper[step++] = 1;  //入栈为1 
					//printf("入栈\n");
					if(A[j]==B[i]) break;
				}
				inStack[A[j++]] = 0;
				oper[step++] = 0;  //出栈为0 
				//printf("出战\n");
				Stack.pop();
			}
			else {
				if(Stack.top()!=B[i]) {  //失败 
					ok = 0;
					break; 
				}
				else {
					oper[step++] = 0;  //出栈为0 
					Stack.pop();
					//printf("出战\n");
				}
			}
		}
		if(!ok) {
			printf("No.\nFINISH\n");
		}
		else {
			printf("Yes.\n");
			for(i=0;i<step;i++) {
				if(oper[i]==1) puts("in");
				else puts("out");
			}
			printf("FINISH\n");
		}
	}
	return 0;
}
