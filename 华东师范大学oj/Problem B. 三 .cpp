#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	double a, b, c, x, y;
	scanf("%lf %lf %lf", &a, &b, &c);
	if(a<b) swap(a, b);
	if(a<c) swap(a, c);  //保证a为最大 
	x = (a*a+b*b-c*c)/(2*a);
	y = sqrt(b*b-x*x);
	printf("0.000 0.000\n");
	printf("%.3lf 0.000\n", a);
	printf("%.3lf %.3lf\n", x, y);
	return 0;
} 
