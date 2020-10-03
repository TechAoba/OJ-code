#include<iostream>
#include<cstdio>
#include<vector>
#define Min(a,b) (a<b?a:b)
#include<algorithm>
using namespace std;
int hang[1005], lie[1005], N, M, K, L, D;
struct Node{
	int id, cnt;
};
vector<Node> VN;
vector<int> V;
bool cmp(Node a, Node b) {
	return a.cnt>b.cnt;
}

int main()
{
	cin>>N>>M>>K>>L>>D;
	int i, x1, x2, y1, y2;
	for(i=0;i<D;i++) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int tmp;
		if(x1==x2) {
			tmp = Min(y1, y2);
			lie[tmp]++;
		}
		else if(y1==y2) {
			tmp = Min(x1, x2);
			hang[tmp]++;
		}
	}
	for(i=1;i<=M;i++) {
		VN.push_back(Node{i, hang[i]});
	}
	sort(VN.begin(), VN.end(), cmp);
	for(i=0;i<K;i++) {
		V.push_back(VN[i].id);
	}
	sort(V.begin(), V.end());
	for(i=0;i<K;i++) {
		printf("%d%c", V[i], i==K-1?'\n':' ');
	}
	VN.clear();  V.clear();
	for(i=1;i<=N;i++) {
		VN.push_back(Node{i, lie[i]});
	}
	sort(VN.begin(), VN.end(), cmp);
	for(i=0;i<L;i++) {
		V.push_back(VN[i].id);
	}
	sort(V.begin(), V.end());
	for(i=0;i<L;i++) {
		printf("%d%c", V[i], i==L-1?'\n':' ');
	}
	return 0;
}
