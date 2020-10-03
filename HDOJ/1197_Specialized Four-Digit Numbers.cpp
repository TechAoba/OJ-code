#include<iostream>
#include<cstdio>
using namespace std;

bool ok(int a) {
	int ans=0, ans1=0, ans2=0;
	ans += (a%10) + ((a%100)/10) + ((a%1000)/100) + (a/1000);
	int t = a;
	ans1 += t/1728, t%=1728;
	ans1 += t/144, t%=144;
	ans1 += t/12, t%=12;
	ans1 += t;
	if(ans!=ans1) return false;
	
	t = a;
	ans2 += t/4096, t%=4096;
	ans2 += t/256, t%=256;
	ans2 += t/16, t%=16;
	ans2 += t;
	if(ans!=ans2) return false;
	return true;
}

int main()
{
	for(int i=1000;i<10000;i++) {
		if(ok(i)) printf("%d\n", i);
	}
	return 0;
}
