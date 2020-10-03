#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1010;
int N, parent[MAXN], deep[MAXN], dis[MAXN], id[MAXN];
bool cmp(int a, int b) {  //按照节点的深度来对节点排序 
	return deep[a] > deep[b];
}

int main()
{
	scanf("%d", &N);
	int i, ans=0, a, b, c;
	dis[0] = dis[1] = N; id[1] = 1;
	for(i=2;i<=N;i++) {
		scanf("%d", &parent[i]);
		dis[i] = N;
		id[i] = i;
		deep[i] = deep[parent[i]] + 1;  //计算节点的深度 
	}
	sort(id+1, id+N+1, cmp);
	for(i=1;i<=N;i++) {
		a = id[i], b = parent[a], c = parent[b];  //a, b, c 子 父 祖
		dis[a] = min(dis[a], min(dis[b]+1, dis[c]+2));
		if(dis[a]>2) {  //子危险  祖加消防栓 
			ans++;
			dis[c] = 0;
			dis[parent[c]] = min(1, dis[parent[c]]);
			dis[parent[parent[c]]] = min(2, dis[parent[parent[c]]]);
		} 
	}
	printf("%d\n", ans);
	return 0;
}
