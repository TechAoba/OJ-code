#include<iostream>
#include<set>
using namespace std;
set<int> S;

int main()
{
	int N, i, val;
	cin>>N;
	for(i=0;i<N;i++) {
		cin>>val;
		S.insert(val);
	}
	int cnt = S.size();
	cout<<cnt<<endl;
	for(set<int>::iterator it=S.begin();it!=S.end();it++) {
		cout<<*it<<" ";
	}
	return 0;
}
