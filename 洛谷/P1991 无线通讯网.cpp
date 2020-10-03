#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int S, P, cnt, X[505], Y[505], parent[505];
struct Edge{
	int u, v;
	double l;
	bool operator <(const Edge &a)const{
		return l<a.l;
	}
}node[125005];

int find(int a) {
	int pa=a, i=parent[a];
	while(parent[pa] != pa) pa = parent[pa];
	while(i!=pa) {
		i=parent[a];
		parent[a] = pa;
		a = i;
	}
	return pa;
}

bool Union(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if(pa==pb) return false;
	parent[pa] = pb;
	return true;
}

int main()
{
	scanf("%d %d", &S, &P);  //P个点 
	int i, j;
	double ans=0;
	for(i=0;i<P;i++) {
		parent[i] = i;
		scanf("%d %d", &X[i], &Y[i]);
		for(j=0;j<i;j++) {
			node[cnt].u = i;
			node[cnt].v = j;
			node[cnt].l = sqrt( (X[i]-X[j])*(X[i]-X[j]) + (Y[i]-Y[j])*(Y[i]-Y[j]) );
			cnt++;
		}
	}
	sort(node, node+cnt);
	j = P-S;  //需要j条边 
	for(i=0;i<cnt;i++) {
		if(Union(node[i].u, node[i].v)) {
			j--;
			if(j==0) {
				ans = node[i].l;
				break;
			}
		}
	}
	printf("%.2lf\n", ans);
	return 0;
}
