#include<iostream>
#include<cstdio>
#define Max(a,b) (a>b?a:b)
using namespace std;
int month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool vis[370];

int main()
{
	int N, i, j, m, d, cnt, ans=2;
	int st[13];
	st[1]=0, st[2]=31;
	for(i=3;i<13;i++) st[i] = st[i-1]+month[i-1];
	vis[1] = 1;  //ÐÇÆÚÌì
	for(i=7;i<370;i+=7) {
		vis[i] = vis[i+1]=1;
	}
	cin>>N;
	for(i=0;i<N;i++) {
		scanf("%d/%d", &m, &d);
		cnt = st[m]+d;
		for(j=cnt;j<367;j++) {
			if(!vis[j]) {
				vis[j] = 1;
				break;
			}
		}
	}
	cnt=0; 
	for(i=1;i<367;i++) {
		//cout<<i<<"   "<<vis[i]<<endl;
		if(vis[i]) {
			cnt++;
		}
		else {
			ans = Max(ans, cnt);
			cnt=0;
		}
	}
	ans = Max(ans, cnt);
	cout<<ans<<endl;
	return 0;
}
