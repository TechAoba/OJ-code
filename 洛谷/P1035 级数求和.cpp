#include<iostream>
using namespace std;
double N, add = 0.0;

int main()
{
	cin>>N;
	int num = 0;
	while(add<=N) {
		num++;
		add += 1.0/(double)num;
	}
	cout<<num;
	return 0;
}
