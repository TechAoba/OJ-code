#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
const int MAXN = 100000+5;
int pp[MAXN];
bool prime[MAXN], vis[MAXN];

int main()
{
	int i, j, a, N, cnt=0;
	for(i=2;i<=MAXN;i++) {
		if(!vis[i]) prime[i] = true, pp[cnt++] = i;  //pp为基础质数 
		for(j=0;j<cnt && i*pp[j]<=MAXN;j++) {  //j循环基础质数 
			vis[i*pp[j]] = true;
			if(i%pp[j]==0) break;
		} 
	}
	vector<int> V;
	cin>>N;
	for(i=0;i<N;i++) {
		cin>>a;
		if(prime[a]) V.push_back(a);
	}
	for(i=0;i<V.size();i++) {
		printf("%d%c", V[i], i==V.size()-1?'\n':' ');
	}
	return 0;
}
