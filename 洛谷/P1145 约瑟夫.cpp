#include<iostream>
#include<cstdio>
using namespace std;

int k, m;

int main()
{
	while(scanf("%d", &k) != EOF) {
		int flag = 1, m = k;
		while(flag) {  		//û���ҵ� 
			int cur = 0;	//��ǰλ�� 
			m++;			//m����k+1 
			for(int i=0;i<k;i++) {    //����k��kill 
				cur = (cur + m - 1) % (2 * k - i);
				if(cur < k) break;
				if(i == k-1) flag = 0;  //�������� 
			}
		}
		printf("%d\n", m); 
	}
	return 0;
}
