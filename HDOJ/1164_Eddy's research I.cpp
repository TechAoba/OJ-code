#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int N;
vector<int> V;

void fun() {
	for(int i=2;i<=N;i++) {
		while(N%i==0) {
			V.push_back(i);
			N/=i;
		}
	}
}

int main()
{
	while(scanf("%d", &N) != EOF) {
		V.clear();
		fun();
		for(int i=0;i<V.size();i++) {
			printf("%d%c", V[i], i==V.size()-1?'\n':'*');
		}
	}
	return 0;
}
