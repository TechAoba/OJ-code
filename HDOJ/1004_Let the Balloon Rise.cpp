#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string,int> Map;
map<string,int>::iterator it;

int main()
{
	int T, i;
	string s;
	while(scanf("%d", &T)==1 && T!=0) {
		Map.clear();
		for(i=0;i<T;i++) {
			cin>>s;
			Map[s]++;
		}
		int Tmax = 0;
		string ans;
		for(it=Map.begin();it!=Map.end();it++) {
			if(it->second > Tmax) {
				Tmax = it->second;
				ans = it->first;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
