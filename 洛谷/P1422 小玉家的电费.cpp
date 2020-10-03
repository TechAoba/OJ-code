#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	double ans = 0.0;
	int cnt;
	cin>>cnt;
	if(cnt>400) {
		ans += (cnt-400) * 0.5663;
		cnt = 400;
	}
	if(cnt>150) {
		ans += (cnt-150) * 0.4663;
		cnt = 150;
	}
	ans+=cnt*0.4463;
	printf("%.1lf", ans);
	return 0;
}
