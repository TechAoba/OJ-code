#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int weishu;

int main()
{
	int A, B;
	while(scanf("%d %d", &A, &B) != EOF) {
		// 首先判断位数
		weishu = 0;
		int t1 = A, t2, i, temp, ans = 0;
		while(t1) {
			weishu++;
			t1 /= 10;
		}
		int mul = pow(10, weishu-1);
		for(t1=A;t1<B;t1++) {
			vector<int> V;
			temp = (t1%mul) * 10 + t1 / mul;
			while(temp != t1) {
				if(temp > t1 && temp <= B) ans++;
				temp = (temp%mul) * 10 + temp / mul;
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
