#include<iostream>
#include<cstdio>
using namespace std;

int k, m;

int main()
{
	while(scanf("%d", &k) != EOF) {
		int flag = 1, m = k;
		while(flag) {  		//没有找到 
			int cur = 0;	//当前位置 
			m++;			//m最少k+1 
			for(int i=0;i<k;i++) {    //进行k次kill 
				cur = (cur + m - 1) % (2 * k - i);
				if(cur < k) break;
				if(i == k-1) flag = 0;  //符合条件 
			}
		}
		printf("%d\n", m); 
	}
	return 0;
}
