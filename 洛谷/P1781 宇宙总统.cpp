#include<iostream>
#include<string>
using namespace std;

int main()
{
	string ans, tmp;
	int len = 0, N, i, best = 1;
	cin>>N;
	for(i=1;i<=N;i++) {
		cin>>tmp;
		int tlen = tmp.size();
		if(tlen>len) {
			ans = tmp;
			len = tlen;
			best = i;
		}
		else if(tlen==len && tmp>ans) {
			ans = tmp;
			best = i;
		}
	}
	cout<<best<<endl<<ans; 
	return 0;
}
