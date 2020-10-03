#include<iostream>
using namespace std;
int A[10];

int main()
{
	int height, i;
	for(i=0;i<10;i++) {
		cin>>A[i];
	}
	cin>>height;
	height += 30;
	int ans = 0;
	for(i=0;i<10;i++) {
		if(height>=A[i]) ans++;
	}
	cout<<ans;
	return 0;
}
