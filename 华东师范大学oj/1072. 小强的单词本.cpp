#include<iostream>
#include<set>
#include<string>
using namespace std;
set<string> word;
int main()
{
	string S;
	int n, i;
	cin>>n;
	for(i=0;i<n;i++) {
		cin>>S;
		word.insert(S);
	}
	for(set<string>::iterator it = word.begin(); it != word.end(); it++) {
		cout<<*it<<endl;
	}
	return 0;
}
