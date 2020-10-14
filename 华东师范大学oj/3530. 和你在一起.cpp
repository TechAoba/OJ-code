#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string A[25];

bool cmp(string a, string b) {
	return a+b>b+a;
}

int main()
{
	int n, a, i;
	cin>>n;
	for(i=0;i<n;i++) {
		cin>>A[i];
	}
	sort(A, A+n, cmp);
	for(i=0;i<n;i++) cout<<A[i];
	return 0;
}
