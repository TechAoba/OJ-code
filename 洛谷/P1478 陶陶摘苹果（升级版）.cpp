#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct apple{
	int height, power;
	apple(int height, int power):height(height),power(power) {}
};
vector<apple> V;

bool cmp(apple a, apple b) {
	return a.power<b.power;
}

int main()
{
	int i, N, s, a, t1, t2, b, tot, cnt = 0;
	cin>>N>>s>>a>>b;
	tot = a+b;
	for(i=0;i<N;i++) {
		cin>>t1>>t2;
		if(t1<=tot) {
			V.push_back(apple(t1, t2));
		}
	}
	sort(V.begin(), V.end(), cmp);
	
	int ans = 0;
	for(i=0;i<V.size();i++) {
		//cout<<i<<"¸ö  "<<V[i].power<<endl;
		if(s<V[i].power) break;
		s -= V[i].power;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
 } 
