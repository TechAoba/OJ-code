#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int N;
string A[28];
bool cmp(string S1, string S2) {
	return S1+S2>S2+S1;
}

int main()
{
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>A[i];
	}
	sort(A+1, A+N+1, cmp);
	for(int i=1;i<=N;i++) cout<<A[i];
	return 0;
} 
