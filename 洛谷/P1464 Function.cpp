#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
int A[22][22][22];
bool vis[22][22][22];


int fun(LL a, LL b, LL c) {
	if(a<=0 || b<=0 || c<=0) return 1;
	if(a>20 || b>20 || c>20) return fun(20, 20, 20);
	if(vis[a][b][c]) return A[a][b][c];
	if(a<b && b<c) {
		A[a][b][c-1] = fun(a, b, c-1);
		A[a][b-1][c-1] = fun(a, b-1, c-1);
		A[a][b-1][c] = fun(a, b-1, c);
		vis[a][b][c-1] = vis[a][b-1][c-1] = vis[a][b-1][c] = true;
		A[a][b][c] = A[a][b][c-1] + A[a][b-1][c-1] - A[a][b-1][c];
		return A[a][b][c];
	}
	A[a-1][b][c] = fun(a-1, b, c);
	A[a-1][b-1][c] = fun(a-1, b-1, c);
	A[a-1][b][c-1] = fun(a-1, b, c-1);
	A[a-1][b-1][c-1] = fun(a-1, b-1, c-1);
	vis[a-1][b][c] = vis[a-1][b-1][c] = true;
	vis[a-1][b][c-1] = vis[a-1][b-1][c-1] = true;
	A[a][b][c] = A[a-1][b][c] + A[a-1][b-1][c] + A[a-1][b][c-1] - A[a-1][b-1][c-1];
	return A[a][b][c];
}

int main()
{
	LL a, b, c;
	A[0][0][0] = 1;
	vis[0][0][0] = true;
	while(cin>>a>>b>>c && !(a==-1&&b==-1&&c==-1)) {
		printf("w(%lld, %lld, %lld) = %d\n", a, b, c, fun(a, b, c));
	}
	return 0;
}
