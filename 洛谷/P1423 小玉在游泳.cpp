#include<iostream>
using namespace std;
double now = 2.0, add = 0.0;

int main()
{
	double target;
	cin>>target;
	int step = 0;
	while(add<target) {
		step++;
		add += now;
		now *= 0.98;
	}
	cout<<step;
	return 0;
}
