#include<iostream>
#include<map>
#include<string>
#include<utility>
using namespace std;
map<string,pair<int, int> > M;
string A[15];

int main()
{
	int N, i, j, a, b, aver, sub;
	string name, t;
	cin>>N;
	for(i=0;i<N;i++) {
		cin>>A[i];
	}	
	for(i=0;i<N;i++) {
		cin>>name;
		cin>>a>>b;
		if(b==0) continue;
		M[name].first = a;  //aÊÇ±¾½ð 
		aver = a/b;
		sub = aver*b;
		M[name].second -= sub;
		for(j=0;j<b;j++) {
			cin>>t;
			M[t].second += aver;
		}
	}
	for(i=0;i<N;i++) {
		cout<<A[i]<<" "<<M[A[i]].second<<endl;
	}
	return 0;
 } 
