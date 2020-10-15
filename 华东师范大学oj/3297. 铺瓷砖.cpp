#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int T, n, num[35][4], use[35][4];

int main()
{
	cin>>T;
	memset(num, 0, sizeof(num));
	memset(use, 0, sizeof(use));
	num[1][1] = num[2][2] = num[3][3] = use[1][1] = 1;
	int i, j, k;
	for(i=3;i<=30;i++) {
		for(j=1;j<=3;j++) {			// 此处使用j长度的瓷砖 
			for(k=1;k<=3;k++) {				// 上一次使用的瓷砖 
				if(j == k) continue;
				num[i][j] += num[i-j][k];
				use[i][j] += use[i-j][k];
				if(j == 1) use[i][j] += num[i-j][k];
			}
			//cout<<i<<" "<<j<<" "<<num[i][j]<<endl;
		}
		//cout<<i<<" "<<use[i]<<endl;
	}
	while(T--) {
		cin>>n;
		cout<<num[n][1]+num[n][2]+num[n][3]<<endl;
		cout<<use[n][1]+use[n][2]+use[n][3]<<endl;
	}
	return 0;
 } 
