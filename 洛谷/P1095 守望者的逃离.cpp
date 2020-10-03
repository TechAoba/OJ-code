#include<iostream>
#include<cstring>
#include<cstdio>
#define Max(a,b) (a>b?a:b)
using namespace std;
const int MAXN = 300000+10;
int dis[MAXN], M, S, T;

int main()
{
	cin>>M>>S>>T;
	int i;
	for(i=1;i<=T;i++) {
		if(M>=10) M-=10, dis[i] = dis[i-1]+60;
		else M+=4, dis[i] = dis[i-1];
	}
	for(i=1;i<=T;i++) {
		dis[i] = Max(dis[i], dis[i-1]+17);
		if(dis[i]>=S) {  //可以逃出去 
			printf("Yes\n%d\n", i);
			return 0;
		}
	}
	printf("No\n%d\n", dis[T]);
	return 0;
}
