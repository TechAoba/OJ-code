#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 1000000+5;
int heap[MAXN], size=0, N;

inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

void add(int x) {
	heap[++size] = x;
	int now=size, Next;
	while(now>=1) {
		Next = now>>1;
		if(heap[Next]<=heap[now]) return;
		swap(heap[now], heap[Next]);
		now = Next;
	}
}

void del() {
	heap[1] = heap[size--];
	int now=1, Next;
	while(now*2<=size) {
		Next = now<<1;
		if(Next+1<=size && heap[Next+1]<=heap[Next]) Next++;
		if(heap[now]<=heap[Next]) return;
		swap(heap[now], heap[Next]);
		now = Next;
	}
}

int main()
{
	N =read();
	int i, x;
	for(i=1;i<=N;i++) {
		x = read();
		if(x==1) {
			x = read();
			add(x);
		}
		else if(x==2) {
			printf("%d\n", heap[1]);
		}
		else if(x==3) {
			del();
		}
	}
	return 0;
}
