#include<iostream>
#define Min(a,b) (a<b?a:b)
using namespace std;
const int MAXN = 200005, INF = 0x3f3f3f3f;
int parent[MAXN], len[MAXN], ans = INF, N;

int find(int a) {
	if(a!=parent[a]) {
		int shang = parent[a];
		parent[a] = find(shang);
		len[a] += len[shang];	
	}
	return parent[a];
}

void point(int a, int b) {
	int pa = find(a), pb = find(b);
	if(pa!=pb) {
		parent[a] = pb;
		len[a] = len[b]+1;
	}
	else ans = Min(ans, len[b]+1);
}

int main()
{
	int i, a;
	cin>>N;
	for(i=1;i<=N;i++) parent[i] = i;
	for(i=1;i<=N;i++) {
		cin>>a;
		point(i, a);
	}
	cout<<ans<<endl;
	return 0;
}
