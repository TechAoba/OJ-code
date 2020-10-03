#include<iostream>
using namespace std;
int num[1005] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int add(int a) {  //输入一个数，返回该数需要的火柴数 
	if(a==0) return 6;
	int sum = 0;
	while(a>0) {
		sum += num[a%10];
		a/=10;
	}
	return sum;
}

int main()
{
	int T, ans = 0, i, j;
	cin>>T;
	T -= 4;
	for(i=10;i<=1000;i++) {
		num[i] = add(i);
	}
	for(i=0;i<=1000;i++) {
		for(j=0;j<=1000;j++) {
			if(i+j>1000) continue;
			if(num[i] + num[j] + num[i+j] == T) {
				ans++;
				//cout<<i<<"  +  "<<j;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
