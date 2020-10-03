#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int N, M;
 
int main()
{
	int i, j, a;
	while(scanf("%d %d", &N, &M) != EOF) {
		vector<int> V;
		for(i=1;i<=N;i++) {
			scanf("%d", &a);
			V.push_back(a);
		}
		for(i=1;i<=M;i++) {
			scanf("%d", &a);
			V.push_back(a);
		}
		sort(V.begin(), V.end());
		printf("%d", V[0]);
		for(i=1;i<V.size();i++) {
			if(V[i] != V[i-1]) printf(" %d", V[i]);
		}
		putchar('\n');
	}
	return 0;
}
