#include<iostream>
#include<cstdio>
#include<cstring>
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
using namespace std;
int R, C, N, Tmax[1005][1005], Tmin[1005][1005];

int main()
{
	scanf("%d %d %d", &R, &C, &N);
	int a, size;
	for(r=1;r<=R;r++) {
		scanf("%d", &a);
		size = Min(r, c);
		if(size==1) Tmax[r][c] = Tmin[r][c] = a;
		else {
			
		}
	}
	return 0;
}
