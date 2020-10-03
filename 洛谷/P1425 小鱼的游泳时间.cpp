#include<iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	cin>>a>>b>>c>>d;
	int ans = (c-a)*60+(d-b);
	cout<<ans/60<<" "<<ans%60;
	return 0;
} 
