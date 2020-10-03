#include<iostream>
#include<cstdio>
#include<cstring>
#define res register int
#define Max(a,b) (a>b?a:b)
using namespace std;
const int MAXN = 1e6+10;
int lchild[MAXN], rchild[MAXN], N, Root=1, ans=0;

/*void fun(int a, int step) {
	if(a==0) return;
	ans = Max(ans, step);
	fun(lchild[a], step+1);
	fun(rchild[a], step+1);
}*/
int fun(int a) {
	if(a==0) return 0;
	res l = lchild[a], r=rchild[a];
	if(l==0 && r==0) return 1;
	return Max(fun(l), fun(r))+1;
}

int main()
{
	int a, b;
	scanf("%d", &N);
	for(res i=1;i<=N;i++) {
		scanf("%d %d", &lchild[i], &rchild[i]);
	}
	printf("%d\n", fun(1));
	return 0;
}
