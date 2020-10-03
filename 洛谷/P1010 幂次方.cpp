#include<iostream>
#include<cstdio>
using namespace std;

void dfs(int num, bool flag) {  //flag 1 -- 递归进来的  0 -- 从主函数进来的 
	if(num==0) {
		printf("0");
		return;
	}
	else if(num==1) {
		if(flag) return;
		else printf("2(0)");
		return;
	}
	else if(num==2) {
		if(flag) printf("2");
		else printf("2(1)");
		return;
	}
	bool start = true;  //第一个数前面没有加号 
	int A[25] = {0}, cur=0, i;
	int TT = num;
	while(num) {
		A[cur++] = num&1;
		num >>= 1;
	}
	for(i=cur-1;i>=0;i--) {
		if(A[i]) {
			if(start) {  //第一个前面没有+号 
				start = false;
			}
			else printf("+");
			printf("2");
			if(i!=1) printf("(");
			dfs(i, true);
			if(i!=1) printf(")");
		}
	}
}

int main()
{
	int num;
	while(cin>>num) {
		dfs(num, false);	
		putchar('\n');
	}
	return 0;
}
