#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> V;

int main()
{
	int N, i, a;
	scanf("%d", &N);
	for(i=1;i<=N;i++) {
		scanf("%d", &a);
		V.insert(lower_bound(V.begin(), V.end(), a), a);
		if(i&1) {
			printf("%d\n", V[(i-1)>>1]);
		}
	}
	return 0;
}
