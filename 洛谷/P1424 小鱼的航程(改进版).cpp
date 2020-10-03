#include<iostream>
#define LL long long
using namespace std;
LL ans = 0;
bool swim[8] = {false, true, true, true, true, true, false, false}; 

int main()
{
	LL day, cnt;
	cin>>day>>cnt;
	LL cir = cnt/7;
	ans += cir*1250;
	cnt %= 7;
	for(int i=day;i<day+cnt;i++) {
		int t = i%7;
		if(t==0) t = 7;
		if(swim[t]) {
			ans += 250;
		}
	}
	cout<<ans;
	return 0;
}
