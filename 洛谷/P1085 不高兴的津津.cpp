#include<iostream>
using namespace std;

int main()
{
	int Tmax = 8, best = 0;
	for(int i=1;i<=7;i++) {
		int a, b;
		cin>>a>>b;
		if(a+b>Tmax) {
			Tmax = a+b;
			best = i;
		} 
	}
	cout<<best;
	return 0;
}
