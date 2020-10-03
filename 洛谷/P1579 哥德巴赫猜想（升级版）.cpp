#include<iostream>
#include<vector>
using namespace std;
const int MAXN = 20005;
bool prime[MAXN], vis[MAXN];
int pp[MAXN];
vector<int> V;

int main()
{
	int cnt = 0, i, j, N;
	cin>>N;
	for(i=2;i<N;i++) {
		if(!vis[i]) prime[i] = true, pp[cnt++] = i;
		for(j=0;j<cnt && i*pp[j]<N;j++) {
			vis[pp[j] * i] = true;
			if(i%pp[j] == 0) break;
		}
	}
	for(i=2;i<N;i++) {
		if(prime[i]) V.push_back(i);
	}
	//for(i=0;i<V.size();i++) cout<<V[i]<<" ";
	bool ok = false;
	for(i=0;i<V.size();i++) {
		for(j=i;j<V.size();j++) {
			if(!prime[N-V[i]-V[j]]) continue;
			cout<<V[i]<<" "<<V[j]<<" "<<N-V[i]-V[j]<<endl;
			ok = true;
			break;
		}
		if(ok) break;
	}
	return 0;
}
