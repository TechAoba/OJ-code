#include<iostream>
#include<cstdio>
using namespace std;
int parent[10000+5];

int read() {
	char c = getchar();
	int num = 0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') {num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	return num;
}

int find(int a) {
	int pa=a, i;
	while(parent[pa]!=pa) pa=parent[pa];
	while(a!=pa) {
		i=parent[a];
		parent[a]=pa;
		a=i;
	}
	return pa;
}

int main()
{
	int N, M, i, j, op, a, b, pa, pb;
	N=read(); M=read();
	for(i=1;i<=N;i++) parent[i]=i;
	for(i=0;i<M;i++) {
		op=read();a=read();b=read();
		pa=find(a), pb=find(b);
		if(op==1) {  //ºÏ²¢ 
			parent[pa] = pb;
		}
		else if(op==2) {  //ÅĞ¶Ï 
			if(pa==pb) printf("Y\n");
			else printf("N\n");
		}
	}
	return 0;
 } 
