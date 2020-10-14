#include<iostream>
using namespace std;

int main()
{
	int year, a, b, c, d;
	cin>>year;
	year++;
	for(;;year++) {
		a=year/1000;
		b=(year/100)%10;
		if(a==b) continue;
		c=(year/10)%10;
		if(a==c||b==c) continue;
		d=year%10;
		if(a==d||b==d||c==d) continue;
		break;
	}
	cout<<year;
	return 0;
}
